#ifndef DEF_SPHERE_H
#define DEF_SPHERE_H

#include "circle.h"
#include "color.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
    Canvas* canvas;
} Sphere;

void sphere_draw_fill(const Sphere* sphere);

#endif
