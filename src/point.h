#ifndef DEF_POINT_H
#define DEF_POINT_H

#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

int point_distance(Point a, Point b);

#endif
