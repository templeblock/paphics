#ifndef DEF_POINT_H
#define DEF_POINT_H

#include <math.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct {
    int x;
    int y;
} Point;

bool point_are_equals(const Point p1, const Point p2) __attribute__((const));

int point_distance(const Point a, const Point b);

Point point_max_x(const Point a, const Point b);

Point point_max_y(const Point a, const Point b);

Point point_min_x(const Point a, const Point b);

Point point_min_y(const Point a, const Point b);

#endif
