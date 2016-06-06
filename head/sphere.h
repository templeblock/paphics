#ifndef DEF_SPHERE_H
#define DEF_SPHERE_H

#include <SDL2/SDL.h>
#include "point.h"
#include "canvas.h"
#include "circle.h"
#include "color.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
} Sphere;

void sphere_draw_fill(Canvas* canvas, Sphere* sphere);

#endif
