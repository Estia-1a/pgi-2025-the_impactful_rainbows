#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char* filename){
    
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s\n", filename);
    } else {
        printf("dimension : %d, %d\n", width, height);
        free_image_data(data);
    }
}

void first_pixel (char* source_path) {
    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s\n", source_path);
    } else {
        printf("first_pixel: %d, %d, %d\n", data[0], data[1], data[2]);
        free_image_data(data);
    }
}

void tenth_pixel (char *source_path){
    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s\n", source_path);
    } else  {
        printf("tenth_pixel: %d, %d, %d\n", data[27], data[28], data[29]);
        free_image_data(data);
    }
}

void second_line(char *source_path) {

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s\n", source_path);
    } else {
        printf("second_line: %d, %d, %d\n", data[0], data[1], data[2]);

        free_image_data(data);
    }
}

void max_pixel(char* filename) {
    unsigned char* data;
    int width, height, n;
 
    if (read_image_data(filename, &data, &width, &height, &n) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }
 
    int max_sum = -1;
    int max_x = 0, max_y = 0;
    pixelRGB max_pixel;
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* p = get_pixel(data, width, height, n, x, y);
            if (p == NULL) continue;
 
            int sum = p->R + p->G + p->B;
            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                max_pixel = *p;
            }
        }
    }
 
    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_pixel.R, max_pixel.G, max_pixel.B);
    free_image_data(data);
}