#include "draw.h"

void draw(Surface surface, ...) {

    va_list ap;

    va_start(ap, surface);


    va_end(ap);

    ;
}

void draw_circle(Surface surface, Point center, int radius, Uint32 color) {

    int i;
    float dx;
    float dy;
    Point min;
    Point max;
    Point pix;

    min.x = center.x - radius;
    max.x = center.x + radius;
    min.y = center.y - radius;
    max.y = center.y + radius;

    for (i = min.x; i <= max.x; i++) {
        dx = i - center.x;
        dy = sqrt(radius * radius - dx * dx);
        pix.x = i;

        pix.y = center.y + dy;
        draw_pixelOld(surface, pix, color);
        pix.y = center.y - dy;
        draw_pixelOld(surface, pix, color);
    }

    for (i = min.y; i <= max.y; i++) {
        dy = i - center.y;
        dx = sqrt(radius * radius - dy * dy);
        pix.y = i;

        pix.x = center.x + dx;
        draw_pixelOld(surface, pix, color);
        pix.x = center.x - dx;
        draw_pixelOld(surface, pix, color);
    }
}

void draw_fill_circle(Surface surface, Point center, int radius, Uint32 color) {

    float dx;
    float dy;
    Point min;
    Point max;
    Point pix;

    min.x = center.x - radius;
    max.x = center.x + radius;
    min.y = center.y - radius;
    max.y = center.y + radius;

    for (pix.x = min.x; pix.x <= max.x; pix.x++) {

        dx = pix.x - center.x;

        for (pix.y = min.y; pix.y <= max.y; pix.y++) {

            dy = pix.y - center.y;

            if (dx * dx + dy * dy <= radius * radius) {
                draw_pixelOld(surface, pix, color);
            }
        }
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

void draw_fill_sphere(Surface surface, Point center, int radius, Uint32 originalColor) {

    int i;
    int nb_step;

    int dred;
    int dgreen;
    int dblue;
    int dradius;

    Uint32 newColor;
    SDL_Color color;
    SDL_Color colorTmp;
    Point pointTmp;
    int radiusTmp;

    color = translate_color(originalColor);

    nb_step = radius * 0.5;

    dred = (255 - color.r) / nb_step;
    dgreen = (255 - color.g) / nb_step;
    dblue = (255 - color.b) / nb_step;

    dradius = radius / nb_step;

    for (i = 0; i < nb_step; i++) {

        colorTmp.r = color.r + dred * i;
        colorTmp.g = color.g + dgreen * i;
        colorTmp.b = color.b + dblue * i;

        pointTmp.x = center.x + i;
        pointTmp.y = center.y + i;

        radiusTmp = radius - dradius * i;

        newColor = SDL_MapRGB(surface.surface->format, colorTmp.r, colorTmp.g, colorTmp.b);

        draw_fill_circle(surface, pointTmp, radiusTmp, newColor);
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
            draw_pixelOld(surface, tmp, color);
        }
    }

    if (min.y == max.y) {
        tmp.y = min.y;

        for (tmp.x = min.x; tmp.x < max.x; tmp.x++) {
            draw_pixelOld(surface, tmp, color);
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

            draw_pixelOld(surface, tmp, color);
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

            draw_pixelOld(surface, tmp, color);
        }
    }
}

void draw_pixel(Surface surface, Pixel pixel) {

    if (pixel.position.x > 0 && pixel.position.y > 0 && pixel.position.x < surface.surface->w && pixel.position.y < surface.surface->h) {
        *((Uint32*) surface.surface->pixels + (surface.surface->h - pixel.position.y - 1) * surface.surface->w + pixel.position.x) = pixel.color;
    }
}

void draw_pixelOld(Surface surface, Point point, Uint32 color) {

    if (point.x > 0 && point.y > 0 && point.x < surface.surface->w && point.y < surface.surface->h) {
        *((Uint32*) surface.surface->pixels + (surface.surface->h - point.y - 1) * surface.surface->w + point.x) = color;
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
