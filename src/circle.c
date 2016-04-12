#include "circle.h"

void circle_draw(Surface surface, Point center, int radius, Uint32 color) {

    int i;
    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;

    pix.color = color;

    min.x = center.x - radius;
    max.x = center.x + radius;
    min.y = center.y - radius;
    max.y = center.y + radius;

    for (i = min.x; i <= max.x; i++) {
        dx = i - center.x;
        dy = sqrt(radius * radius - dx * dx);
        pix.position.x = i;

        pix.position.y = center.y + dy;
        pixel_draw(surface, &pix);
        pix.position.y = center.y - dy;
        pixel_draw(surface, &pix);
    }

    for (i = min.y; i <= max.y; i++) {
        dy = i - center.y;
        dx = sqrt(radius * radius - dy * dy);
        pix.position.y = i;

        pix.position.x = center.x + dx;
        pixel_draw(surface, &pix);
        pix.position.x = center.x - dx;
        pixel_draw(surface, &pix);
    }
}

void circle_draw_fill(Surface surface, Point center, int radius, Uint32 color) {

    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;

    pix.color = color;

    min.x = center.x - radius;
    max.x = center.x + radius;
    min.y = center.y - radius;
    max.y = center.y + radius;

    for (pix.position.x = min.x; pix.position.x <= max.x; pix.position.x++) {

        dx = pix.position.x - center.x;

        for (pix.position.y = min.y; pix.position.y <= max.y; pix.position.y++) {

            dy = pix.position.y - center.y;

            if (dx * dx + dy * dy <= radius * radius) {
                pixel_draw(surface, &pix);
            }
        }
    }
}
