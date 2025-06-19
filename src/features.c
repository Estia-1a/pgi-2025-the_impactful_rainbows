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

void dimension(char* filename) {
    int width, height, channel_count;
     unsigned char* data;
    
    int result = read_image_data(filename, &data, &width, &height, &channel_count);

    if (result == 0) {
        printf("Erreur avec le fichier: %s\n", filename);
    } else {
        printf("dimension: %d, %d\n", width, height);
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
    unsigned char* data;
    int width, height, channel_count;
    
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    if (result == 0) {
        printf("Erreur avec le fichier: %s\n", source_path);
        return;
    }

    int max_value = 0;
    int max_x = 0;
    int max_y = 0;
    
    int component_index;
    if (component == 'R') {
        component_index = 0;
    } else if (component == 'G') {
        component_index = 1;
    } else if (component == 'B') {
        component_index = 2;
    } else {
        printf("Composante invalide. Utilisez R, G ou B\n");
        free_image_data(data);
        return;
    }
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_start = (y * width + x) * channel_count;
            int current_value = data[pixel_start + component_index];
            
            if (current_value > max_value) {
                max_value = current_value;
                max_x = x;
                max_y = y;
            }
        }
    }
    
    printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);
    free_image_data(data);
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
void max_pixel(char* filename) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int max_sum = -1;
    int max_x = 0, max_y = 0;
    int max_r = 0, max_g = 0, max_b = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_start = (y * width + x) * channel_count;
            
            int r = data[pixel_start + 0];
            int g = data[pixel_start + 1];
            int b = data[pixel_start + 2];
            int sum = r + g + b;
            
            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                max_r = r;
                max_g = g;
                max_b = b;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_r, max_g, max_b);
    free_image_data(data);
}

void min_component(char *source_path, char component) {
    unsigned char* data;
    int width, height, channel_count;

    int result = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (result == 0) {
        printf("Erreur avec le fichier: %s\n", source_path);
        return;
    }

    int min_value = 255;
    int min_x = 0;
    int min_y = 0;

    int component_index;
    if (component == 'R') {
        component_index = 0;
    } else if (component == 'G') {
        component_index = 1;
    } else if (component == 'B') {
        component_index = 2;
    } else {
        printf("Composante invalide. Utilisez R, G ou B\n");
        free_image_data(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_start = (y * width + x) * channel_count;
            int current_value = data[pixel_start + component_index];

            if (current_value < min_value) {
                min_value = current_value;
                min_x = x;
                min_y = y;
            }
        }
    }

    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);

    free_image_data(data);
}

void color_red(char* filename) {
    unsigned char *data;
    int i, width, height, channel_count, total_pixels, pixel_start;

    read_image_data(filename, &data, &width, &height, &channel_count);

    total_pixels = width * height;

    for (i = 0; i < total_pixels; i++) {
        pixel_start = i * channel_count;

        data[pixel_start + 1] = 0;
        data[pixel_start + 2] = 0;
    }

    write_image_data("image_out.bmp", data, width, height);
}
void min_pixel(char* filename) {
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }

    int min_sum = 255 * 3 + 1;
    int min_x = 0, min_y = 0;
    int min_r = 0, min_g = 0, min_b = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_start = (y * width + x) * channel_count;
            
            int r = data[pixel_start + 0];
            int g = data[pixel_start + 1];  
            int b = data[pixel_start + 2];
            int sum = r + g + b;
            
            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
                min_r = r;
                min_g = g;
                min_b = b;
            }
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_r, min_g, min_b);
    free_image_data(data);
}
void color_blue(char* filename) {
    unsigned char *data;
    int i, width, height, channel_count, total_pixels, pixel_start;

    read_image_data(filename, &data, &width, &height, &channel_count);

    total_pixels = width * height;

    for (i = 0; i < total_pixels; i++) {
        pixel_start = i * channel_count;

        data[pixel_start] = 0;
        data[pixel_start + 1] = 0;
    }

    write_image_data("image_out.bmp", data, width, height);
}

void color_green(char* filename) {
    unsigned char *data;
    int i, width, height, channel_count, total_pixels, pixel_start;

    read_image_data(filename, &data, &width, &height, &channel_count);

    total_pixels = width * height;

    for (i = 0; i < total_pixels; i++) {
        pixel_start = i * channel_count;

        data[pixel_start] = 0;
        data[pixel_start + 2] = 0;
    }

    write_image_data("image_out.bmp", data, width, height);
}

void color_invert(char* filename) {
    unsigned char *data;
    int i, width, height, channel_count, total_pixels, pixel_start;

    read_image_data(filename, &data, &width, &height, &channel_count);

    total_pixels = width * height;

    for (i = 0; i < total_pixels; i++) {
        pixel_start = i * channel_count;

        data[pixel_start] = 255 - data[pixel_start];
        data[pixel_start + 1] = 255 - data[pixel_start + 1];
        data[pixel_start + 2] = 255 - data[pixel_start + 2];
    }
    write_image_data("image_out.bmp", data, width, height);
}
void color_gray(char *filename) {
    unsigned char *data;
    int i, width, height, channel_count, total_pixels, pixel_start;
    unsigned char gray_value;

    read_image_data(filename, &data, &width, &height, &channel_count);

    total_pixels = width * height;
 
    for (i = 0; i < total_pixels; i++) {
        pixel_start = i * channel_count;
        gray_value = (data[pixel_start] + data[pixel_start + 1] + data[pixel_start + 2]) / 3;
       
        data[pixel_start] = gray_value;
        data[pixel_start + 1] = gray_value;
        data[pixel_start + 2] = gray_value;
    }
    write_image_data("image_out.bmp", data, width, height);
}
void color_gray_luminance(char *filename) {
    unsigned char *data;
    int i, width, height, channel_count, total_pixels, pixel_start;
    unsigned char gray_value;

    read_image_data(filename, &data, &width, &height, &channel_count);

    total_pixels = width * height;

    for (i = 0; i < total_pixels; i++) {
        pixel_start = i * channel_count;
        
        gray_value = (0.21 * data[pixel_start] + 0.72 * data[pixel_start + 1] + 0.07 * data[pixel_start + 2]);

        data[pixel_start] = gray_value;     
        data[pixel_start + 1] = gray_value; 
        data[pixel_start + 2] = gray_value; 
    }

    write_image_data("image_out.bmp", data, width, height);
}
void scale_crop(char* filename) {
    unsigned char *data, *new_data;
    int i, j, width, height, channel_count;
    
    read_image_data(filename, &data, &width, &height, &channel_count);
    
    // Définir les paramètres de crop pour cibler la zone du poteau
    int crop_width = width / 3;  // 1/3 de la largeur
    int crop_height = height;    // toute la hauteur
    int center_x = (width * 3) / 4;  // vers la droite de l'image
    int center_y = height / 2;       // centre vertical
    
    new_data = malloc(crop_width * crop_height * channel_count);
    
    int start_x = center_x - crop_width / 2;
    int start_y = center_y - crop_height / 2;
    
    for (i = 0; i < crop_height; i++) {
        for (j = 0; j < crop_width; j++) {
            int src_x = start_x + j;
            int src_y = start_y + i;
            
            int new_pixel = (i * crop_width + j) * channel_count;
            
            if (src_x >= 0 && src_x < width && src_y >= 0 && src_y < height) {
                int src_pixel = (src_y * width + src_x) * channel_count;
                new_data[new_pixel] = data[src_pixel];
                new_data[new_pixel + 1] = data[src_pixel + 1];
                new_data[new_pixel + 2] = data[src_pixel + 2];
            } else {
                new_data[new_pixel] = 0;
                new_data[new_pixel + 1] = 0;
                new_data[new_pixel + 2] = 0;
            }
        }
    }
    
    write_image_data("image_out.bmp", new_data, crop_width, crop_height);
    free(new_data);
}