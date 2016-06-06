#ifndef DEF_POINT_H
#define DEF_POINT_H

#include <math.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct {
    int x;
    int y;
} Point;

bool equals(Point p1, Point p2) __attribute__((const));

int point_distance(Point a, Point b);

void point_sort_leftToRight(int nbOfPoints, Point* tab, ...);

void point_sort_topToBottom(int nbOfPoints, Point* tab, ...);

Point point_max_x(Point a, Point b);

Point point_max_y(Point a, Point b);

Point point_min_x(Point a, Point b);

Point point_min_y(Point a, Point b);

bool point_is_greater_x(Point a, Point b);

bool point_is_greater_y(Point a, Point b);

#endif
