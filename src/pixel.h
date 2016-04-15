#ifndef DEF_PIXEL_H
#define DEF_PIXEL_H

#include <SDL2/SDL.h>
#include "point.h"
#include "surface.h"

typedef struct {
    Point position;
    Uint32 color;
    // void (*pDraw)(Surface, Pixel);
} Pixel;

Pixel pixel_create();

void pixel_draw(Surface* surface, Pixel* pixel);

#endif
