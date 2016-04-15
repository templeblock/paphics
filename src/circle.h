#ifndef DEF_CIRCLE_H
#define DEF_CIRCLE_H

#include <SDL2/SDL.h>
#include "surface.h"
#include "point.h"
#include "pixel.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
} Circle;

void circle_draw(Surface* surface, Circle* circle);

void circle_draw_fill(Surface* surface, Circle* circle);

#endif
