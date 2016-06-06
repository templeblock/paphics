#ifndef DEF_PIXEL_H
#define DEF_PIXEL_H

#include <SDL2/SDL.h>
#include "point.h"
#include "canvas.h"

typedef struct {
    Point position;
    Uint32 color;
} Pixel;

void pixel_draw(Canvas* canvas, Pixel* pixel);

#endif