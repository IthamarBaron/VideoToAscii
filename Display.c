#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "VideoToFrames.h"
#include "ImageToAscii.h"

#define FRAME_FOLDER "frames"
#define FRAME_COUNT 2200 // max frames 
#define FRAME_DELAY 10000

// Function to play the extracted ASCII frames
char filename[256];
void PlayAsciiVideo() {

    for (int i = 1; i <= FRAME_COUNT; i++) {
        snprintf(filename, sizeof(filename), "%s/frame_%04d.png", FRAME_FOLDER, i); // load the filename
        system("cls");
        ImageToAscii(filename); // Convert frame to ASCII and print
        Sleep(FRAME_DELAY / 1000);
    }
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: %s <video_path>\n", argv[0]);
        return 1;
    }

    char* videoPath = argv[1];

    printf("Extracting frames from: %s\n", videoPath);
    ExtractFrames(videoPath); 
    printf("Frames extracted! Playing ASCII animation...\n");
    PlayAsciiVideo();

    return 0;
}
