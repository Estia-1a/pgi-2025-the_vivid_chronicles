#include <estia-image.h>
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>

pixel *get_pixel(unsigned char *data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    if (x >= width || y >= height) {
        return NULL;
    }
    int position = (y * width + x) * n;
    pixel *p = malloc(sizeof(pixel));
    if (p == NULL) {
        return NULL;
    }
    p->r = data[position];
    p->g = data[position + 1];
    p->b = data[position + 2];
    
    return p;
}