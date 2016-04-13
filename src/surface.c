#include "surface.h"

Surface surface_create(Point size, Point origin, Surface parent) {

    Surface newSurface;
    SDL_Surface* newSDL_Surface;

    newSDL_Surface = NULL;
    newSDL_Surface = SDL_CreateRGBSurface(0, size.x, size.y, 32, 0, 0, 0, 0);

    if(newSDL_Surface == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }

    newSurface.size = size;
    newSurface.parent = parent.surface;
    newSurface.surface = newSDL_Surface;

    newSurface.origin = origin;
    //newSurface.origin.y = parent.size.y - origin.y - 2;


    return newSurface;

}

void surface_blit(Surface* surface) {

    SDL_Rect dest_rect;

    dest_rect.w = surface->size.x;
    dest_rect.h = surface->size.y;
    dest_rect.x = surface->origin.x;
    dest_rect.y = surface->origin.y;

    if (SDL_BlitSurface(surface->surface, NULL, surface->parent, &dest_rect) < 0) {
        fprintf(stderr, "\nBlit failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }

}

void surface_clear(Surface* surface) {

    SDL_FillRect(surface->surface, NULL, 0x000000);
}

void surface_draw_borders_in(Surface* surface, Uint32 color) {

    Point a;
    Point b;

    a.x = 1;
    a.y = 1;

    b = surface->size;

    b.x--;
    b.y--;

    rectangle_draw(surface, a, b, color);
}

void surface_draw_borders_out(Surface* surface, Uint32 color) {

    Surface tmp;
    tmp.surface = surface->parent;

    Point a;
    Point b;

    a = surface->origin;
    b = a;

    a.x--;
    a.y--;

    b.x += surface->size.x;
    b.y += surface->size.y;

    rectangle_draw(&tmp, a, b, color);
}

void surface_load_img(Surface* surface, char* pathToImg) {

    SDL_Surface* tmp;

    tmp = NULL;

    tmp = IMG_Load(pathToImg);

    if (tmp == NULL) {
        fprintf(stderr, "\nUnable to load image %s! SDL Error: %s\n", pathToImg, SDL_GetError());
        graphics_error_quit();
    }

    SDL_BlitSurface(tmp, NULL, surface->surface, NULL );

    SDL_FreeSurface(tmp);

}
