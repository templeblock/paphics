#include "point.h"

bool point_are_equals(const Point p1, const Point p2) {

    bool eq;
    
    if (p1.x != p2.x) {
        eq = false;
    } else if (p1.y != p2.y) {
        eq = false;
    } else {
        eq = true;
    }
    
    return eq;
}

int point_distance(const Point a, const Point b) {

    int distance;
    
    distance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    
    float distanceTmp;
    
    distanceTmp = sqrtf((float) distance);
    
    distance = (int) distanceTmp;
    
    return distance;
}

Point point_max_x(const Point a, const Point b) {

    Point max;
    
    if (a.x > b.x) {
        max = a;
    } else if (b.x > a.x) {
        max = b;
    } else if (a.y != b.y) {
        max = point_max_y(a, b);
    } else {
        max = a;
    }
    
    return max;
}

Point point_max_y(const Point a, const Point b) {

    Point max;
    
    if (a.y > b.y) {
        max = a;
    } else if (b.y > a.y) {
        max = b;
    } else if (a.x != b.x) {
        max = point_max_x(a, b);
    } else {
        max = a;
    }
    
    return max;
}

Point point_min_x(const Point a, const Point b) {

    Point min;
    
    if (point_are_equals(point_max_x(a, b), a)) {
        min = b;
    } else {
        min = a;
    }
    
    return min;
}

Point point_min_y(const Point a, const Point b) {

    Point min;
    
    if (point_are_equals(point_max_y(a, b), a)) {
        min = b;
    } else {
        min = a;
    }
    
    return min;
}

bool point_is_greater_x(const Point a, const Point b) {

    bool is_greater;
    
    if (point_are_equals(point_max_x(a, b), a)) {
        is_greater = true;
    } else {
        is_greater = false;
    }
    
    return is_greater;
}

bool point_is_greater_y(const Point a, const Point b) {

    bool is_greater;
    
    if (point_are_equals(point_max_y(a, b), a)) {
        is_greater = true;
    } else {
        is_greater = false;
    }
    
    return is_greater;
}
