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
        draw_pixel(surface, &pix);
        pix.position.y = center.y - dy;
        draw_pixel(surface, &pix);
    }

    for (i = min.y; i <= max.y; i++) {
        dy = i - center.y;
        dx = sqrt(radius * radius - dy * dy);
        pix.position.y = i;

        pix.position.x = center.x + dx;
        draw_pixel(surface, &pix);
        pix.position.x = center.x - dx;
        draw_pixel(surface, &pix);
    }
}

void draw_fill_circle(Surface surface, Point center, int radius, Uint32 color) {

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
                draw_pixel(surface, &pix);
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
        draw_line(surface, &line);
    }
}

void draw_fill_sphere(Surface surface, Sphere* sphere) {

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

    color = translate_color(sphere->color);

    nb_step = sphere->radius * 0.5;

    dred = (255 - color.r) / nb_step;
    dgreen = (255 - color.g) / nb_step;
    dblue = (255 - color.b) / nb_step;

    dradius = sphere->radius / nb_step;

    for (i = 0; i < nb_step; i++) {

        colorTmp.r = color.r + dred * i;
        colorTmp.g = color.g + dgreen * i;
        colorTmp.b = color.b + dblue * i;

        pointTmp.x = sphere->center.x + i;
        pointTmp.y = sphere->center.y + i;

        radiusTmp = sphere->radius - dradius * i;

        newColor = SDL_MapRGB(surface.surface->format, colorTmp.r, colorTmp.g, colorTmp.b);

        draw_fill_circle(surface, pointTmp, radiusTmp, newColor);
    }
}

void draw_line(Surface surface, Line* line) {

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
            draw_pixel(surface, &pix);
        }
    }

    if (min.y == max.y) {
        pix.position.y = pix.position.y;

        for (pix.position.x = min.x; pix.position.x < max.x; pix.position.x++) {
            draw_pixel(surface, &pix);
        }
    }

    // max var x
    if ((max.x - min.x >= max.y - min.y) && (max.y - min.y > 0)) {
        c = (float) (a.y - b.y) / ((float) a.x - b.x);
        d = a.y - c * a.x;

        for (pix.position.x = min.x; pix.position.x < max.x; pix.position.x++) {

            k = c * pix.position.x + d;
            pix.position.y = k;

            if (((k - pix.position.y) > 0.5) && (pix.position.y < surface.size.y - 1)) {
                pix.position.y++;
            }

            draw_pixel(surface, &pix);
        }
    }

    // max var y
    if ((max.y - min.y > max.x - min.x) && (max.x - min.x > 0)) {
        c = (float) (a.y - b.y) / ((float) (a.x - b.x));
        d = a.y - c * a.x;

        for (pix.position.y = min.y; pix.position.y < max.y; pix.position.y++) {

            k = (pix.position.y - d) / c;
            pix.position.x = k;

            if (((k - pix.position.x) > 0.5) && (pix.position.x < surface.size.x - 1)) {
                pix.position.x++;
            }

            draw_pixel(surface, &pix);
        }
    }
}

void draw_pixel(Surface surface, Pixel* pixel) {

    if (pixel->position.x > 0 && pixel->position.y > 0 && pixel->position.x < surface.surface->w && pixel->position.y < surface.surface->h) {
        *((Uint32*) surface.surface->pixels + (surface.surface->h - pixel->position.y - 1) * surface.surface->w + pixel->position.x) = pixel->color;
    }
}

void draw_rectangle(Surface surface, Point a, Point b, Uint32 color) {

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

    draw_line(surface, &l);
    draw_line(surface, &m);
    draw_line(surface, &n);
    draw_line(surface, &o);

}
