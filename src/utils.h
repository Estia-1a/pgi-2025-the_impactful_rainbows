#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>


typedef struct _pixelRGB {
    unsigned char R;
    unsigned char G;    
    unsigned char B; 
} pixelRGB ;

pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y);

void setPixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB pixel);

pixelRGB *getPixel(unsigned char* data, const unsigned int width, const unsigned int height,
                    const unsigned int n, const unsigned int x, const unsigned int y);


void print_pixel( char *source_path, int x, int y );

#endif
