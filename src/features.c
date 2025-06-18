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

                if (component_value > max_component_value) {
                    max_component_value = component_value;
                    max_x = x;
                    max_y = y;
                }
            }
        }
 
        printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_component_value);

    } else {
        printf("Erreur lors de la lecture de l'image.\n");
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

void rotate_cw(char* source_path) {
    int width, height, nbChannels;
    unsigned char *source_data;
    unsigned char *target_data;
 
    if (read_image_data(source_path, &source_data, &width, &height, &nbChannels)) {
        target_data = (unsigned char *)malloc(width * height * nbChannels * sizeof(unsigned char));
 
        int target_width = height;
        int target_height = width;
 
        int y, x;
        for (y = 0; y < height; y++){
            for (x = 0; x < width; x++){
                int source_pixel_index = (y * width + x) * nbChannels;
                int target_pixel_index = ((x * target_width) + (target_width - 1 - y)) * nbChannels;
 
                target_data[target_pixel_index] = source_data[source_pixel_index];
                target_data[target_pixel_index + 1] = source_data[source_pixel_index + 1];
                target_data[target_pixel_index + 2] = source_data[source_pixel_index + 2];
 
                if (nbChannels == 4){
                    target_data[target_pixel_index +3] = source_data[source_pixel_index + 3];
                }
            }
        }
        write_image_data("image_out.bmp", target_data, target_width, target_height);
 
        free(source_data);
        free(target_data);
    }
}
void rotate_acw(char* source_path) {
    int width, height, nbChannels;
    unsigned char* source_data;
    unsigned char* target_data;
 
    if (read_image_data(source_path, &source_data, &width, &height, &nbChannels)) {
        target_data = (unsigned char*)malloc(width * height * nbChannels * sizeof(unsigned char));
        int target_width = height;
        int target_height = width;
 
        int y, x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int source_pixel_index = (y * width + x) * nbChannels;
                int target_pixel_index = ((target_height - 1 - x) * target_width + y) * nbChannels;
 
                target_data[target_pixel_index] = source_data[source_pixel_index];
                target_data[target_pixel_index + 1] = source_data[source_pixel_index + 1];
                target_data[target_pixel_index + 2] = source_data[source_pixel_index + 2];
 
                if (nbChannels == 4) {
                    target_data[target_pixel_index + 3] = source_data[source_pixel_index + 3];
                }
            }
        }
        write_image_data("image_out.bmp", target_data, target_width, target_height);
 
        free(source_data);
        free(target_data);
    }
}