#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_RESIZE2_IMPLEMENTATION
#include "stb_image_resize2.h"
#include <stdio.h>
#include <stdlib.h>

#define TARGET_WIDTH 100
#define TARGET_HEIGHT 50
#define IMAGE_PATH "C:\\Users\\itham\\Desktop\\temp\\bad1.png"

// Define ASCII characters for brightness 
const char* ASCII_CHARS = " .:-=+*#%@";

void image_to_ascii(const char* filename)
{
    int width, height, channels;
    unsigned char* img = stbi_load(filename, &width, &height, &channels, 1); // Load as grayscale

    if (!img) {
        printf("Failed to load image!\n");
        return;
    }

    printf("Original Image: %d x %d\n", width, height);

    // Allocate memory for resized image
    unsigned char* resized_img = (unsigned char*)malloc(TARGET_WIDTH * TARGET_HEIGHT);
    if (!resized_img) {
        printf("Failed to allocate memory for resized image!\n");
        stbi_image_free(img);
        return;
    }

    // Resize image
    stbir_resize(img, width, height, 0, resized_img, TARGET_WIDTH, TARGET_HEIGHT, 0, 1, STBIR_TYPE_UINT8, STBIR_FILTER_DEFAULT, STBIR_EDGE_CLAMP);

    // Free original image memory
    stbi_image_free(img);

    // Convert resized image to ASCII
    for (int y = 0; y < TARGET_HEIGHT; y++) {
        for (int x = 0; x < TARGET_WIDTH; x++) {
            int pixel_index = y * TARGET_WIDTH + x;
            unsigned char pixel_value = resized_img[pixel_index];

            // Map brightness (0-255) to ASCII range
            int ascii_index = (pixel_value * 9) / 255; // 9 is max index of ASCII_CHARS
            printf("%c", ASCII_CHARS[ascii_index]);
        }
        printf("\n");
    }

    // Free resized image memory
    free(resized_img);
}

int main() {
    image_to_ascii(IMAGE_PATH);
    return 0;
}

