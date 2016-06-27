#ifndef DEF_SPHERE_H
#define DEF_SPHERE_H

#include "circle.h"
#include "color.h"

#pragma pack(push, 1)
typedef struct {
    Point center;
    int radius;
    Canvas* canvas;
} Sphere;
#pragma pack(pop)

void sphere_draw_fill(const Sphere* sphere, const Uint32 color);

#endif
