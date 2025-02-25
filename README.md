# VideoToASCII

## Overview
VideoToASCII is a C-based project that extracts frames from a video, converts each frame to ASCII characters, and displays them as an animation in the console. The program utilizes FFmpeg for frame extraction and the STB library for image processing.

## Features
- Extracts frames from a video using FFmpeg
- Converts frames to ASCII characters based on brightness
- Plays the ASCII animation in the terminal

## Dependencies
This project uses the following libraries:
- **FFmpeg**: For extracting frames from the video
- **stb_image.h**: For loading images
- **stb_image_resize.h**: For resizing images

## Project Structure
```
VideoToASCII/
├── ffmpeg.exe             # FFmpeg binary for frame extraction
├── frames/                # Folder where extracted frames are stored
├── VideoToFrames.h        # Header file for frame extraction
├── ImageToAscii.h         # Header file for ASCII conversion
├── VideoToFrames.c        # Handles frame extraction from video
├── ImageToAscii.c         # Converts images to ASCII
├── Display.c              # Main program

```

## Installation
1. Download and extract the repository.
2. Download and extract the required FFmpeg binary and DLLs from the release section.
3. Ensure that `ffmpeg.exe` is placed in the project root directory.
   
⚠️ The requirements can be found here:
[Download ZIP](https://github.com/Ithamarbaron/VideoToAscii/releases)


## Usage
Run the program from the terminal:
```sh
VideoToASCII.exe <video_file_path>
```

This will extract frames from `video_file_path`, convert them to ASCII, and display the animation in the console.

## Notes
- Ensure that FFmpeg is present in the project directory.
- The extracted frames are stored in the `frames/` folder and are automatically deleted before new frames are extracted.
- The program uses 2200 frames by default but you can config it.


