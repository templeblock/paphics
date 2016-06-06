#ifndef DEF_QUADRILATERAL_H
#define DEF_QUADRILATERAL_H

#include <SDL2/SDL.h>
#include "point.h"
#include "canvas.h"
#include "line.h"

void quadrilateral_draw(Canvas canvas, Point p1, Point p2, Point p3, Point p4, Uint32 color);

#endif