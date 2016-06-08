#include "image.h"

void image_blit_naive(Canvas* canvas, Image* image) {

    SDL_BlitSurface(image->surface, NULL, canvas->surface, NULL );
    
}

void image_blit_scaled(Canvas* canvas, Image* image) {

    SDL_BlitScaled(image->surface, NULL, canvas->surface, NULL );
    
}

void image_load(Image* image, char* pathToImg) {

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
