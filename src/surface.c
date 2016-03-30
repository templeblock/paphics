#include "surface.h"

Surface create_surface(Point size, Point origin, Surface parent) {

    Surface newSurface;
    SDL_Surface* newSDL_Surface;

    newSDL_Surface = NULL;
    newSDL_Surface = SDL_CreateRGBSurface(0, size.x, size.y, 32, 0, 0, 0, 0);

    if(newSDL_Surface == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        error_quit();
    }

    newSurface.size = size;
    newSurface.parent = parent.surface;
    newSurface.surface = newSDL_Surface;

    newSurface.origin = origin;
    //newSurface.origin.y = parent.size.y - origin.y - 2;


    return newSurface;

}

void blit_surface(Surface surface) {

    SDL_Rect dest_rect;

    dest_rect.w = surface.size.x;
    dest_rect.h = surface.size.y;
    dest_rect.x = surface.origin.x;
    dest_rect.y = surface.origin.y;

    if (SDL_BlitSurface(surface.surface, NULL, surface.parent, &dest_rect) < 0) {
        fprintf(stderr, "\nBlit failed: %s\n", SDL_GetError());
        error_quit();
    }

}

void clear_surface(Surface surface) {

    SDL_FillRect(surface.surface, NULL, 0x000000);
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
