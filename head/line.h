#ifndef DEF_LINE_H
#define DEF_LINE_H

#include "pixel.h"

typedef struct {
    Point a;
    Point b;
    Canvas* canvas;
} Line;

void line_draw(const Line* line, const Uint32 color);

void line_draw_bis(const Line* line, const Uint32 color);

void line_draw_ter(const Line* line, const Uint32 color);

#endif
