#ifndef DEF_CIRCLE_H
#define DEF_CIRCLE_H

#include "pixel.h"

#pragma pack(push, 1)
typedef struct {
    Point center;
    int radius;
    Canvas* canvas;
} Circle;
#pragma pack(pop)

void circle_draw(const Circle* circle, const Uint32 color);

void circle_draw_fill(const Circle* circle, const Uint32 color);

#endif
