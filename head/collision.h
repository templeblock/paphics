#ifndef DEF_COLLISION_H
#define DEF_COLLISION_H

#include <stdbool.h>
#include "canvas.h"
#include "point.h"

bool collision_is_out_of_canvas(Canvas* canvas, Point a, int radius);

bool collision_is_out_of_canvas_x(Canvas* canvas, int a, int radius);

bool collision_is_out_of_canvas_y(Canvas* canvas, int a, int radius);

#endif
