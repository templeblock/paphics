#ifndef DEF_LINE_H
#define DEF_LINE_H

#include "pixel.h"

typedef struct {
    Point a;
    Point b;
    Uint32 color;
} Line;

void line_draw(Canvas* canvas, const Line* line);

void line_draw_bis(Canvas* canvas, const Line* line);

void line_draw_ter(Canvas* canvas, const Line* line);

void line_draw_generic(Canvas* canvas, const Line* line, const short int algoNumber);

#endif
