#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld(){
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

void first_pixel (char* source_path){
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

void second_line(char *source_path){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier: %s\n", source_path);
    } else {
        printf("second_line: %d, %d, %d\n", data[0], data[1], data[2]);

        free_image_data(data);
    }
}
void max_component(char *source_path, char component) {
    int width;
    int height;
    int nbChannels;
    unsigned char *data;
 
    if (read_image_data(source_path, &data, &width, &height, &nbChannels)) {
        int max_component_value = -1;
        int max_x = 0;
        int max_y = 0;
 
        int y;
        int x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int pixel_index = (y * width + x) * nbChannels;
                int R = data[pixel_index];
                int G = data[pixel_index + 1];
                int B = data[pixel_index + 2];
                int component_value;
 
                if (component == 'R' || component == 'r') {
                    component_value = R;
                } else if (component == 'G' || component == 'g') {
                    component_value = G;
                } else if (component == 'B' || component == 'b') {
                    component_value = B;
                } else {
                    printf("Option de composante invalide.\n");
                    return;
                }
                if (component_value > max_component_value) {
                    max_component_value = component_value;
                    max_x = x;
                    max_y = y;
                }
            }
        }
 
        printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_component_value);
    }
 
}

void print_pixel(char *source_path, int x, int y) {

    unsigned char* data = NULL;
    int width, height, channel;

    int result = read_image_data(source_path, &data, &width, &height, &channel);
    if (result == 0 || data == NULL) {
        printf("Error reading image\n");
        return;
    }

    pixelRGB* px = getPixel(data, width, height, channel, x, y);
    if (px) {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, px->R, px->G, px->B);
    } else {
        printf("Invalid pixel position (%d, %d)\n", x, y);
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

void min_component(char *source_path, char component) {
    int width;
    int height;
    int nbChannels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &nbChannels)) {
        int min_component_value = 256;
        int min_x = 0;
        int min_y = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int pixel_index = (y * width + x) * nbChannels;
                int R = data[pixel_index];
                int G = data[pixel_index + 1];
                int B = data[pixel_index + 2];
                int component_value;

                if (component == 'R' || component == 'r') {
                    component_value = R;
                } else if (component == 'G' || component == 'g') {
                    component_value = G;
                } else if (component == 'B' || component == 'b') {
                    component_value = B;
                } else {
                    printf("Option de composante invalide.\n");
                    return;
                }

                if (component_value < min_component_value) {
                    min_component_value = component_value;
                    min_x = x;
                    min_y = y;
                }
            }
        }

        printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_component_value);
    } else {
        printf("Erreur lors de la lecture de l'image.\n");
    }
}

void color_red (char* filenames){
    int width , height, nbChannels;
    unsigned char *data;
    read_image_data(filenames, &data, &width, &height, &nbChannels);
    int x;
    int y;
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){
            data[y*width*3 + x*3+1] = 0;
            data[y*width*3 + x*3+2] = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void min_pixel(char* filename) {
    unsigned char* data;
    int width, height, n;
 
    if (read_image_data(filename, &data, &width, &height, &n) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }
 
    int min_sum = 255 * 3 + 1;
    int min_x = 0, min_y = 0;
    pixelRGB min_pixel;
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* p = get_pixel(data, width, height, n, x, y);
            if (p == NULL) continue;
 
            int sum = p->R + p->G + p->B;
            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
                min_pixel = *p;
            }
        }
    }
 
    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);
    free_image_data(data);
}
void color_bleu (char* filenames){
    int width , height, nbChannels;
    unsigned char *data;
    read_image_data(filenames, &data, &width, &height, &nbChannels);
    int x;
    int y;
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){
            data[y*width*3 + x*3] = 0;
            data[y*width*3 + x*3+1] = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}
void color_green (char* filenames){
    int width , height, nbChannels;
    unsigned char *data;
    read_image_data(filenames, &data, &width, &height, &nbChannels);
    int x;
    int y;
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){
            data[y*width*3 + x*3+2] = 0;
            data[y*width*3 + x*3+3] = 0;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}