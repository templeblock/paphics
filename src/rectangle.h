#ifndef DEF_RECTANGLE_H
#define DEF_RECTANGLE_H

#include <SDL2/SDL.h>
#include "surface.h"
#include "point.h"
#include "line.h"

typedef struct {
    Point origin;
    Point size;
} Rectangle;

void rectangle_draw(Surface* surface, Point a, Point b, Uint32 color);

void rectangle_draw_fill(Surface* surface, Point a, Point b, Uint32 color);

#endif
