#include "rectangle.h"

void rectangle_draw(Surface* surface, Point a, Point b, Uint32 color) {

    Line l;
    Line m;
    Line n;
    Line o;

    Point c;
    Point d;

    c.x = a.x;
    c.y = b.y;

    d.x = b.x;
    d.y = a.y;

    l.a = a;
    l.b = c;
    m.a = b;
    m.b = c;
    n.a = a;
    n.b = d;
    o.a = b;
    o.b = d;

    l.color = color;
    m.color = color;
    n.color = color;
    o.color = color;

    line_draw(surface, &l);
    line_draw(surface, &m);
    line_draw(surface, &n);
    line_draw(surface, &o);

}

void rectangle_draw_fill(Surface* surface, Point a, Point b, Uint32 color) {

    int i;
    Point top_left;
    Point bottom_left;
    Point top_right;
    Point bottom_tmp;
    Point top_tmp;

    Line line;

    line.color = color;

    if (a.x <= b.x) {
        bottom_left.x = a.x;
        top_left.x = a.x;
        top_right.x = b.x;
    } else {
        bottom_left.x = b.x;
        top_left.x = b.x;
        top_right.x = a.x;
    }

    if (a.y <= b.y) {
        bottom_left.y = a.y;
        top_right.y = b.y;
        top_left.y = b.y;
    } else {
        bottom_left.y = b.y;
        top_right.y = a.y;
        top_left.y = a.y;
    }

    top_tmp = top_left;
    bottom_tmp = bottom_left;

    for (i = 0; i < top_right.x - bottom_left.x; i++) {
        bottom_tmp.x += 1; // replacing 1 per i gives a funny effect
        top_tmp.x += 1;
        line.a = bottom_tmp;
        line.b = top_tmp;
        line_draw(surface, &line);
    }
}
