#ifndef DEF_LINE_H
#define DEF_LINE_H

#include <SDL2/SDL.h>
#include "point.h"
#include "pixel.h"
#include "surface.h"

typedef struct {
    Point a;
    Point b;
    Uint32 color;
} Line;

void line_draw(Surface* surface, Line* line);

#endif
