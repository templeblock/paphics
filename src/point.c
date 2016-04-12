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

void point_sort_leftToRight(int nbOfPoints, Point* tab, ...) {

    int i;
    int j;
    Point tmp;
    va_list ap;

    va_start(ap, tab);

    for (i = 0; i < nbOfPoints; i++) {
        tmp = va_arg(ap, Point);
        tab[i] = tmp;
    }

    va_end(ap);

    for (i = 1; i < nbOfPoints; i++) {
        tmp = tab[i];

        for (j = i; j > 0 && point_is_greater_x(tab[j - 1], tmp); j--) {
            tab[j] = tab[j - 1];
        }

        tab[j] = tab[i];
    }
}

void point_sort_topToBottom(int nbOfPoints, Point* tab, ...) {

    int i;
    int j;
    Point tmp;
    va_list ap;

    va_start(ap, tab);

    for (i = 0; i < nbOfPoints; i++) {
        tmp = va_arg(ap, Point);
        tab[i] = tmp;
    }

    va_end(ap);

    for (i = 1; i < nbOfPoints; i++) {
        tmp = tab[i];

        for (j = i; j > 0 && point_is_greater_y(tab[j - 1], tmp); j--) {
            tab[j] = tab[j - 1];
        }

        tab[j] = tab[i];
    }

}

Point point_max_x(Point a, Point b) {

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

Point point_max_y(Point a, Point b) {

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

Point point_min_x(Point a, Point b) {

    Point min;

    if (equals(point_max_x(a, b), a)) {
        min = b;
    } else {
        min = a;
    }

    return min;
}

Point point_min_y(Point a, Point b) {

    Point min;

    if (equals(point_max_y(a, b), a)) {
        min = b;
    } else {
        min = a;
    }

    return min;
}

bool point_is_greater_x(Point a, Point b) {

    bool is_greater;

    if (equals(point_max_x(a, b), a)) {
        is_greater = true;
    } else {
        is_greater = false;
    }

    return is_greater;
}

bool point_is_greater_y(Point a, Point b) {

    bool is_greater;

    if (equals(point_max_y(a, b), a)) {
        is_greater = true;
    } else {
        is_greater = false;
    }

    return is_greater;
}
