#include <stdio.h>
#include <stdlib.h>

#define VIDEO_PATH "C:\\Users\\itham\\Desktop\\temp\\badApple.mp4"
#define OUTPUT_FOLDER "frames"
#define FPS 10
#define SCALE_WIDTH 100
#define SCALE_HEIGHT 50


void DeleteFolder(const char* folder) {
    char command[256];
    snprintf(command, sizeof(command), "rmdir /s /q %s", folder);
    system(command);
}

void ExtractFrames(char* videoPath) {
    char command[256];

    //Reload the frames folder
    DeleteFolder(OUTPUT_FOLDER);
    _mkdir(OUTPUT_FOLDER);

    // Construct the FFmpeg command to extract frames (and close cmd after execution)
    snprintf(command, sizeof(command),
         "cmd /c ffmpeg -i %s -vf \"fps=%d,scale=%d:%d\" %s/frame_%%04d.png",
         videoPath, FPS, SCALE_WIDTH, SCALE_HEIGHT, OUTPUT_FOLDER);



    printf("Running command: %s\n", command);

    // Run the command
    system(command);
}
