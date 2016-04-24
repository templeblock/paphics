#include "line.h"

void line_draw(Canvas* canvas, Line* line) {
    line_draw_naive(canvas, line);
}

void line_draw_naive(Canvas* canvas, Line* line) {

    Point min;
    Point max;
    Pixel pix;
    Point a;
    Point b;
    Uint32 color;

    float c;
    float d;
    float k;

    a = line->a;
    b = line->b;
    color = line->color;
    pix.color = color;

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
        pix.position.x = min.x;

        for (pix.position.y = min.y; pix.position.y <= max.y; pix.position.y++) {
            pixel_draw(canvas, &pix);
        }
    }

    if (min.y == max.y) {
        pix.position.y = min.y;

        for (pix.position.x = min.x; pix.position.x < max.x; pix.position.x++) {
            pixel_draw(canvas, &pix);
        }
    }

    // max var x
    if ((max.x - min.x >= max.y - min.y) && (max.y - min.y > 0)) {
        c = (float) (a.y - b.y) / ((float) a.x - b.x);
        d = a.y - c * a.x;

        for (pix.position.x = min.x; pix.position.x < max.x; pix.position.x++) {

            k = c * pix.position.x + d;
            pix.position.y = k;

            if (((k - pix.position.y) > 0.5) && (pix.position.y < canvas->size.y - 1)) {
                pix.position.y++;
            }

            pixel_draw(canvas, &pix);
        }
    }

    // max var y
    if ((max.y - min.y > max.x - min.x) && (max.x - min.x > 0)) {
        c = (float) (a.y - b.y) / ((float) (a.x - b.x));
        d = a.y - c * a.x;

        for (pix.position.y = min.y; pix.position.y < max.y; pix.position.y++) {

            k = (pix.position.y - d) / c;
            pix.position.x = k;

            if (((k - pix.position.x) > 0.5) && (pix.position.x < canvas->size.x - 1)) {
                pix.position.x++;
            }

            pixel_draw(canvas, &pix);
        }
    }
}
