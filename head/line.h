#ifndef DEF_LINE_H
#define DEF_LINE_H

#include "pixel.h"

typedef struct {
    Point a;
    Point b;
    Uint32 color;
} Line;

void line_draw(Canvas* canvas, const Line* line);

void line_draw_noVarX(Canvas* canvas, const Line* line);

void line_draw_noVarY(Canvas* canvas, const Line* line);

void line_draw_sameVarXY(Canvas* canvas, const Line* line);

void line_draw_naive(Canvas* canvas, const Line* line);

void line_draw_dda(Canvas* canvas, const Line* line, const Point* dist, const Point* dist_abs);

void line_draw_bresenham(Canvas* canvas, const Line* line, const Point* dist);

#endif
