#ifndef DEF_COLLISION_H
#define DEF_COLLISION_H

#include <stdbool.h>
#include "surface.h"
#include "point.h"

bool is_out_of_surface_x(Surface surface, int a, int radius);

bool is_out_of_surface_y(Surface surface, int a, int radius);

#endif
