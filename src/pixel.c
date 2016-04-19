#include "pixel.h"

Pixel pixel_create() {

    Pixel newPixel;

    // newPixel.pDraw = &draw_pixel;

    return newPixel;
}

void pixel_draw(Canvas* canvas, Pixel* pixel) {

    if (pixel->position.x > 0 && pixel->position.y > 0 && pixel->position.x < canvas->surface->w && pixel->position.y < canvas->surface->h) {
        *((Uint32*) canvas->surface->pixels + (canvas->surface->h - pixel->position.y - 1) * canvas->surface->w + pixel->position.x) = pixel->color;
    }
}
