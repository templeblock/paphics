#ifndef DEF_RECTANGLE_H
#define DEF_RECTANGLE_H

#include "point.h"
#include "line.h"

typedef struct {
    Point origin;
    Point size;
    Canvas* canvas;
} Rectangle;

void rectangle_draw(const Rectangle* rectangle, const Uint32 color);

void rectangle_draw_fill(const Rectangle* rectangle, const Uint32 color);

#endif
