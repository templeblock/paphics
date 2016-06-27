#ifndef DEF_CIRCLE_H
#define DEF_CIRCLE_H

#include "pixel.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
    Canvas* canvas;
} Circle;

void circle_draw(const Circle* circle);

void circle_draw_fill(const Circle* circle);

#endif
