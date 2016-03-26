#include "draw.h"

void draw_circle(Surface surface, Point center, int radius, Uint32 color) {

    int i;
    float dx;
    float dy;
    float dr;
    Point min;
    Point max;
    Point pix;

    min.x = center.x - radius;
    max.x = center.x + radius;
    min.y = center.y - radius;
    max.y = center.y + radius;

    dr = radius * radius;

    for (i = min.x; i <= max.x; i++) {
        dx = i - center.x;
        dy = sqrt(dr - dx * dx);
        pix.x = i;

        pix.y = center.y + dy;
        add_pixel(surface, pix, color);
        pix.y = center.y - dy;
        add_pixel(surface, pix, color);
    }

    for (i = min.y; i <= max.y; i++) {
        dy = i - center.y;
        dx = sqrt(dr - dy * dy);
        pix.y = i;

        pix.x = center.x + dx;
        add_pixel(surface, pix, color);
        pix.x = center.x - dx;
        add_pixel(surface, pix, color);
    }
}

void draw_fill_rectangle(Surface surface, Point a, Point b, Uint32 color) {


    int i;
    Point top_left;
    Point bottom_left;
    Point top_right;
    Point bottom_tmp;
    Point top_tmp;

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
        draw_line(surface, bottom_tmp, top_tmp, color);
    }
}

void draw_line(Surface surface, Point a, Point b, Uint32 color) {

    Point min;
    Point max;

    Point tmp;

    float c;
    float d;
    float k;

    if (a.x < b.x) {
        min.x = a.x;
        max.x = b.x;
    } else {
        min.x = b.x;
        max.x = a.x;
    }

    if (a.y < b.y) {
        min.y = a.y;
        max.y = b.y;
    } else {
        min.y = b.y;
        max.y = a.y;
    }

    if (min.x == max.x) {
        tmp.x = min.x;

        for (tmp.y = min.y; tmp.y <= max.y; tmp.y++) {
            add_pixel(surface, tmp, color);
        }
    }

    if (min.y == max.y) {
        tmp.y = min.y;

        for (tmp.x = min.x; tmp.x < max.x; tmp.x++) {
            add_pixel(surface, tmp, color);
        }
    }

    // max var x
    if ((max.x - min.x >= max.y - min.y) && (max.y - min.y > 0)) {
        c = (float) (a.y - b.y) / ((float) a.x - b.x);
        d = a.y - c * a.x;

        for (tmp.x = min.x; tmp.x < max.x; tmp.x++) {

            k = c * tmp.x + d;
            tmp.y = k;

            if (((k - tmp.y) > 0.5) && (tmp.y < surface.size.y - 1)) {
                tmp.y++;
            }

            add_pixel(surface, tmp, color);
        }
    }

    // max var y
    if ((max.y - min.y > max.x - min.x) && (max.x - min.x > 0)) {
        c = (float) (a.y - b.y) / ((float) (a.x - b.x));
        d = a.y - c * a.x;

        for (tmp.y = min.y; tmp.y < max.y; tmp.y++) {

            k = (tmp.y - d) / c;
            tmp.x = k;

            if (((k - tmp.x) > 0.5) && (tmp.x < surface.size.x - 1)) {
                tmp.x++;
            }

            add_pixel(surface, tmp, color);
        }
    }
}

void draw_rectangle(Surface surface, Point a, Point b, Uint32 color) {

    Point c;
    Point d;

    c.x = a.x;
    c.y = b.y;

    d.x = b.x;
    d.y = a.y;

    draw_line(surface, a, c, color);
    draw_line(surface, b, c, color);
    draw_line(surface, a, d, color);
    draw_line(surface, b, d, color);

}
