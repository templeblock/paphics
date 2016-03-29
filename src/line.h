#ifndef DEF_LINE_H
#define DEF_LINE_H

#include <SDL2/SDL.h>
#include "point.h"

typedef struct {
    Point a;
    Point b;
    Uint32 color;
} Line;

#endif
