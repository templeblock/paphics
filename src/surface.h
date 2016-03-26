#ifndef DEF_SURFACE_H
#define DEF_SURFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "point.h"

typedef struct {
    SDL_Surface* surface;
    Point size;
} Surface;

#endif

void add_pixel(Surface surface, Point point, Uint32 color);

void load_surface_img(Surface surface, char* pathToImg);
