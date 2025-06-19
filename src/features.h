#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension(char* filename);

void first_pixel (char *source_path);

void tenth_pixel (char *source_path);

void second_line (char *source_path);

void max_pixel(char *filename);

void max_component(char *source_path, char component);

void print_pixel (char *source_path, int x, int y);

void rotate_cw (char* source_path);

void rotate_acw (char* source_path);

void color_red(char *filenames);

void min_pixel(char* filename);
 
void color_blue(char *filenames);

void color_green(char *filenames);

void color_gray(char *filenames);

void color_invert(char *filenames);

void color_gray_luminance(char *filenames); 

void scale_crop(char* filename);

#endif

