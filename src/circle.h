#ifndef DEF_CIRCLE_H
#define DEF_CIRCLE_H

#include <SDL2/SDL.h>
#include "point.h"

typedef struct {
    Point center;
    int radius;
    Uint32 color;
} Circle;

#endif
