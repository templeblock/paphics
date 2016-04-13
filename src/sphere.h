#ifndef DEF_SPHERE_H
#define DEF_SPHERE_H

#include <SDL2/SDL.h>
#include "point.h"
#include "surface.h"
#include "circle.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
} Sphere;

void sphere_draw_fill(Surface* surface, Sphere* sphere);

#endif
