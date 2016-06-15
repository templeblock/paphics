#ifndef DEF_IMAGE_H
#define DEF_IMAGE_H

#include "graphics.h"

typedef struct {
    SDL_Surface* surface;
} Image;

void image_blit_naive(Canvas* canvas, const Image* image);

void image_blit_scaled(Canvas* canvas, const Image* image);

void image_load(Image* image, const char* pathToImg);

void image_unload(Image* image);

#endif
