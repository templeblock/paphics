#ifndef DEF_CIRCLE_H
#define DEF_CIRCLE_H

#include "pixel.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
} Circle;

void circle_draw(Canvas* canvas, const Circle* circle);

void circle_draw_fill(Canvas* canvas, const Circle* circle);

#endif
