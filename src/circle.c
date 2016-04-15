#include "circle.h"

void circle_draw(Surface* surface, Circle* circle) {

    int i;
    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;

    pix.color = circle->color;

    min.x = circle->center.x - circle->radius;
    max.x = circle->center.x + circle->radius;
    min.y = circle->center.y - circle->radius;
    max.y = circle->center.y + circle->radius;

    for (i = min.x; i <= max.x; i++) {
        dx = i - circle->center.x;
        dy = sqrt(circle->radius * circle->radius - dx * dx);
        pix.position.x = i;

        pix.position.y = circle->center.y + dy;
        pixel_draw(surface, &pix);
        pix.position.y = circle->center.y - dy;
        pixel_draw(surface, &pix);
    }

    for (i = min.y; i <= max.y; i++) {
        dy = i - circle->center.y;
        dx = sqrt(circle->radius * circle->radius - dy * dy);
        pix.position.y = i;

        pix.position.x = circle->center.x + dx;
        pixel_draw(surface, &pix);
        pix.position.x = circle->center.x - dx;
        pixel_draw(surface, &pix);
    }
}

void circle_draw_fill(Surface* surface, Circle* circle) {

    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;

    pix.color = circle->color;

    min.x = circle->center.x - circle->radius;
    max.x = circle->center.x + circle->radius;
    min.y = circle->center.y - circle->radius;
    max.y = circle->center.y + circle->radius;

    for (pix.position.x = min.x; pix.position.x <= max.x; pix.position.x++) {

        dx = pix.position.x - circle->center.x;

        for (pix.position.y = min.y; pix.position.y <= max.y; pix.position.y++) {

            dy = pix.position.y - circle->center.y;

            if (dx * dx + dy * dy <= circle->radius * circle->radius) {
                pixel_draw(surface, &pix);
            }
        }
    }
}
