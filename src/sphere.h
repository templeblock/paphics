#ifndef DEF_SPHERE_H
#define DEF_SPHERE_H

#include <SDL2/SDL.h>
#include "point.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
} Sphere;

#endif
