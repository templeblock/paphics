#include "draw.h"

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
