#include "point.h"

bool equals(Point p1, Point p2) {

    bool eq;

    eq = true;

    if (p1.x != p2.x) {
        eq = false;
    } else if (p1.y != p2.y) {
        eq = false;
    }

    return eq;
}

int point_distance(Point a, Point b) {

    int distance;

    distance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

    distance = (int) sqrt(distance);

    return distance;
}
