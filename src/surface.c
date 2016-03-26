#include "surface.h"

void add_pixel(Surface surface, Point point, Uint32 color) {

    if (point.x > 0 && point.y > 0 && point.x < surface.surface->w && point.y < surface.surface->h) {
        *((Uint32*) surface.surface->pixels + (surface.surface->h - point.y - 1) * surface.surface->w + point.x) = color;
    }
}

void load_surface_img(Surface surface, char* pathToImg) {

    SDL_Surface* tmp;

    tmp = NULL;

    tmp = IMG_Load(pathToImg);

    if (tmp == NULL) {
        fprintf(stderr, "\nUnable to load image %s! SDL Error: %s\n", pathToImg, SDL_GetError());
        error_quit();
    }

    SDL_BlitSurface(tmp, NULL, surface.surface, NULL );

    SDL_FreeSurface(tmp);

}
