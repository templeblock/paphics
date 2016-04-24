#ifndef DEF_LINE_H
#define DEF_LINE_H

#include <SDL2/SDL.h>
#include "point.h"
#include "pixel.h"
#include "canvas.h"

typedef struct {
    Point a;
    Point b;
    Uint32 color;
} Line;

void line_draw(Canvas* canvas, Line* line);

void line_draw_naive(Canvas* canvas, Line* line);

#endif
