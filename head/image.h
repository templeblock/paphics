#ifndef DEF_IMAGE_H
#define DEF_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"

typedef struct {
    SDL_Surface* surface;
} Image;

void image_blit_naive(Canvas* canvas, Image* image);

void image_blit_scaled(Canvas* canvas, Image* image);

void image_load(Image* image, char* pathToImg);

void image_unload(Image* image);

#endif
