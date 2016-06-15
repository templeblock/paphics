#ifndef DEF_COLLISION_H
#define DEF_COLLISION_H

#include "canvas.h"

bool collision_is_out_of_canvas(const Canvas* canvas, const Point a, const int radius);

bool collision_is_out_of_canvas_x(const Canvas* canvas, const int a, const int radius);

bool collision_is_out_of_canvas_y(const Canvas* canvas, const int a, const int radius);

#endif
