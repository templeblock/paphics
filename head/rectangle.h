#ifndef DEF_RECTANGLE_H
#define DEF_RECTANGLE_H

#include "point.h"
#include "line.h"

typedef struct {
    Point origin;
    Point size;
} Rectangle;

void rectangle_draw(Canvas* canvas, Point a, Point b, Uint32 color);

void rectangle_draw_fill(Canvas* canvas, Point a, Point b, Uint32 color);

#endif
