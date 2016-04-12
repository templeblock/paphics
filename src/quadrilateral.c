#include "quadrilateral.h"

void quadrilateral_draw(Surface surface, Point p1, Point p2, Point p3, Point p4, Uint32 color) {

    Point max_left;
    Point max_right;
    Point other1;
    Point other2;

    if (p1.x <= p2.x && p1.x <= p2.x && p1.x <= p3.x && p1.x <= p4.x) {
        max_left = p1;
    } else if (p2.x <= p3.x && p2.x <= p4.x) {
        max_left = p2;
    } else if (p3.x <= p4.x) {
        max_left = p3;
    } else {
        max_left = p4;
    }

    if (p1.x >= p2.x && p1.x >= p2.x && p1.x >= p3.x && p1.x >= p4.x) {
        max_right = p1;
    } else if (p2.x >= p3.x && p2.x >= p4.x) {
        max_right = p2;
    } else if (p3.x >= p4.x) {
        max_right = p3;
    } else {
        max_right = p4;
    }

    if (!(equals(p1, max_left)) && !(equals(p1, max_right))) {
        other1 = p1;
    } else if (!(equals(p2, max_left)) && !(equals(p2, max_right))) {
        other1 = p2;
    } else if (!(equals(p3, max_left)) && !(equals(p3, max_right))) {
        other1 = p3;
    } else {
        other1 = p4;
    }

    if (!(equals(p1, max_left)) && !(equals(p1, max_right)) && !(equals(p1, other1))) {
        other2 = p1;
    } else if (!(equals(p2, max_left)) && !(equals(p2, max_right)) && !(equals(p2, other1))) {
        other2 = p2;
    } else if (!(equals(p4, max_left)) && !(equals(p4, max_right)) && !(equals(p4, other1))) {
        other2 = p4;
    } else {
        other2 = p3;
    }

    Line line1;
    Line line2;
    Line line3;
    Line line4;

    line1.a = max_left;
    line1.b = other1;

    line2.a = other1;
    line2.b = max_right;

    line3.a = max_right;
    line3.b = other2;

    line4.a = other2;
    line4.b = max_left;

    line1.color = color;
    line2.color = color;
    line3.color = color;
    line4.color = color;

    line_draw(surface, &line1);
    line_draw(surface, &line2);
    line_draw(surface, &line3);
    line_draw(surface, &line4);

}
