#ifndef DEF_PIXEL_H
#define DEF_PIXEL_H

#include "canvas.h"

typedef struct {
    Point position;
    Uint32 color;
} Pixel;

void pixel_draw(Canvas* canvas, const Pixel* pixel);

#endif
