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

void line_draw_noVarX(Canvas* canvas, Line* line);

void line_draw_noVarY(Canvas* canvas, Line* line);

void line_draw_sameVarXY(Canvas* canvas, Line* line);

void line_draw_naive(Canvas* canvas, Line* line);

void line_draw_dda(Canvas* canvas, Line* line, Point* dist, Point* dist_abs);

void line_draw_bresenham(Canvas* canvas, Line* line, Point* dist);

void line_draw_other(Canvas* canvas, Line* line);

#endif
