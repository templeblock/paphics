#ifndef DEF_SURFACE_H
#define DEF_SURFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"

typedef struct {
    SDL_Surface* surface;
} Surface;

#endif

void load_surface_img(Surface surface, char* pathToImg);
