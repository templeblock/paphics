#ifndef DEF_PIXEL_H
#define DEF_PIXEL_H

#include "canvas.h"

typedef struct {
    Point position;
    Canvas* canvas;
} Pixel;

void pixel_draw(const Pixel* pixel, const Color* color);

#endif
