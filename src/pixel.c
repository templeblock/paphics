#include "pixel.h"

void pixel_draw(const Pixel* pixel, const Uint32 color) {

    if (pixel->position.x < 0 || pixel->position.y < 0 || pixel->position.x > pixel->canvas->size.x || pixel->position.y > pixel->canvas->size.y) {
        fprintf(stderr, "\nWarning: trying to draw a pixel outside of the canvas: pixel (%d, %d)\n", pixel->position.x, pixel->position.y);
    } else {
        *((Uint32*) pixel->canvas->surface->pixels + (pixel->canvas->size.y - pixel->position.y - 1) * pixel->canvas->size.x + pixel->position.x) = color;
    }
}
