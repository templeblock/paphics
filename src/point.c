#include "point.h"

int point_distance(Point a, Point b) {

    int distance;

    distance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

    distance = (int) sqrt(distance);

    return distance;
}
