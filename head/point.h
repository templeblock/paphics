#ifndef DEF_POINT_H
#define DEF_POINT_H

#include <math.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct {
    int x;
    int y;
} Point;

bool equals(const Point p1, const Point p2) __attribute__((const));

int point_distance(const Point a, const Point b);

void point_sort_leftToRight(const int nbOfPoints, Point* tab, ...);

void point_sort_topToBottom(const int nbOfPoints, Point* tab, ...);

Point point_max_x(const Point a, const Point b);

Point point_max_y(const Point a, const Point b);

Point point_min_x(const Point a, const Point b);

Point point_min_y(const Point a, const Point b);

bool point_is_greater_x(const Point a, const Point b);

bool point_is_greater_y(const Point a, const Point b);

#endif
