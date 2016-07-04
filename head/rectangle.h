#ifndef DEF_RECTANGLE_H
#define DEF_RECTANGLE_H

#include "point.h"
#include "line.h"
#include "color.h"

typedef struct {
    Point origin;
    Point size;
    Canvas* canvas;
} Rectangle;

void rectangle_draw(const Rectangle* rectangle, const Color* color);

void rectangle_draw_fill(const Rectangle* rectangle, const Color* color);

bool rectangle_contains_point(const Rectangle* rect, const Point* p) __attribute__((pure));

bool rectangle_contains_absolute_point(const Rectangle* rect, const Point* p);

#endif
