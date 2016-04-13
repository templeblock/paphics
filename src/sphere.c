#include "sphere.h"

void sphere_draw_fill(Surface* surface, Sphere* sphere) {

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

        pointTmp.x = sphere->center.x + i;
        pointTmp.y = sphere->center.y + i;

        radiusTmp = sphere->radius - dradius * i;

        newColor = SDL_MapRGB(surface->surface->format, colorTmp.r, colorTmp.g, colorTmp.b);

        circle_draw_fill(surface, pointTmp, radiusTmp, newColor);
    }
}
