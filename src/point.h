#ifndef DEF_POINT_H
#define DEF_POINT_H

#include <math.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

bool equals(Point p1, Point p2);

int point_distance(Point a, Point b);

#endif
