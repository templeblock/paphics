#include "sphere.h"

void sphere_draw_fill(Canvas* canvas, Sphere* sphere) {

    int i;
    int nb_step;

    int dred;
    int dgreen;
    int dblue;
    int dradius;
    SDL_Color color;
    SDL_Color colorTmp;
    Circle circle;

    color = graphics_translate_color(sphere->color);

    nb_step = sphere->radius * 0.5;

    dred = (255 - color.r) / nb_step;
    dgreen = (255 - color.g) / nb_step;
    dblue = (255 - color.b) / nb_step;

    dradius = sphere->radius / nb_step;

    for (i = 0; i < nb_step; i++) {

        colorTmp.r = color.r + dred * i;
        colorTmp.g = color.g + dgreen * i;
        colorTmp.b = color.b + dblue * i;

        circle.center.x = sphere->center.x + i;
        circle.center.y = sphere->center.y + i;

        circle.radius = sphere->radius - dradius * i;

        circle.color = SDL_MapRGB(canvas->surface->format, colorTmp.r, colorTmp.g, colorTmp.b);

        circle_draw_fill(canvas, &circle);
    }
}
