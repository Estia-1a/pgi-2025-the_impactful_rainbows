#include "estia-image.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */
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
