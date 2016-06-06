#ifndef DEF_CIRCLE_H
#define DEF_CIRCLE_H

#include <SDL2/SDL.h>
#include "canvas.h"
#include "point.h"
#include "pixel.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
} Circle;

void circle_draw(Canvas* canvas, Circle* circle);

void circle_draw_fill(Canvas* canvas, Circle* circle);

#endif
