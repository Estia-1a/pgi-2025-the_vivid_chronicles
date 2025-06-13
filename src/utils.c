#include <estia-image.h>

#include "utils.h"

pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    if (!data || x >= width || y >= height || n < 3) {
        return NULL;
    }

    return (pixelRGB*) &data[(y * width + x) * n];
}

