
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <estia-image.h>


pixelRGB * getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    if (!data || x >= width || y >= height || n < 3) {
        return NULL;
    }

    unsigned int index = (y * width + x) * n;
    return (pixelRGB *) &data[index];

}

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    if (!data || x >= width || y >= height) return NULL;
 
    unsigned int index = (y * width + x) * n;
    pixelRGB* pixel = (pixelRGB*)malloc(sizeof(pixelRGB));
    if (!pixel) return NULL;
 
    pixel->R = data[index];
    pixel->G = data[index + 1];
    pixel->B = data[index + 2];
 
    return pixel;
}
