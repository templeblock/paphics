#include "pixel.h"

void pixel_draw(Canvas* canvas, Pixel* pixel) {

    if (pixel->position.x < 0 || pixel->position.y < 0 || pixel->position.x > canvas->size.x || pixel->position.y > canvas->size.y) {
        fprintf(stderr, "\nWarning: trying to draw a pixel outside of the canvas: pixel (%d, %d)\n", pixel->position.x, pixel->position.y);
    } else {
        *((Uint32*) canvas->surface->pixels + (canvas->size.y - pixel->position.y - 1) * canvas->size.x + pixel->position.x) = pixel->color;
    }
    
}
