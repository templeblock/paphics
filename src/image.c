#include "image.h"

void image_blit_naive(Canvas* canvas, const Image* image) {

    if (SDL_BlitSurface(image->surface, NULL, canvas->surface, NULL) != 0) {
        fprintf(stderr, "\nUnable to blit image (naive) ! SDL Error: %s\n", SDL_GetError());
        error_quit();
    }
    
}

void image_blit_scaled(Canvas* canvas, const Image* image) {

    if (SDL_BlitScaled(image->surface, NULL, canvas->surface, NULL) != 0) {
        fprintf(stderr, "\nUnable to blit image (scaled) ! SDL Error: %s\n", SDL_GetError());
        error_quit();
    }
    
}

void image_load(Image* image, const char* pathToImg) {

    image->surface = NULL;
    
    image->surface = IMG_Load(pathToImg);
    
    if (image->surface == NULL) {
        fprintf(stderr, "\nUnable to load image %s! SDL Error: %s\n", pathToImg, SDL_GetError());
        error_quit();
    }
}

void image_unload(Image* image) {

    SDL_FreeSurface(image->surface);
    
}
