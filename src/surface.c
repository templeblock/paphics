#include "surface.h"

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
