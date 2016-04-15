#include "pixel.h"

Pixel pixel_create() {

    Pixel newPixel;

    // newPixel.pDraw = &draw_pixel;

    return newPixel;
}

void pixel_draw(Surface* surface, Pixel* pixel) {

    if (pixel->position.x > 0 && pixel->position.y > 0 && pixel->position.x < surface->surface->w && pixel->position.y < surface->surface->h) {
        *((Uint32*) surface->surface->pixels + (surface->surface->h - pixel->position.y - 1) * surface->surface->w + pixel->position.x) = pixel->color;
    }
}
