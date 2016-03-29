#ifndef DEF_PIXEL_H
#define DEF_PIXEL_H

#include <SDL2/SDL.h>
#include "point.h"

typedef struct {
    Point position;
    Uint32 color;
    // void (*pDraw)(Surface, Pixel);
} Pixel;

Pixel create_pixel();

#endif
