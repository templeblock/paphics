#ifndef DEF_DRAW_H
#define DEF_DRAW_H

#include <SDL2/SDL.h>
#include "surface.h"
#include "point.h"
#include "graphics.h"

void draw_line(Surface surface, Point a, Point b, Uint32 color);

#endif
