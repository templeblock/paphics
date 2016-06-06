#include "graphics.h"

void graphics_error_quit() {
    IMG_Quit();
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void graphics_init(Uint32 flags) {

    if (SDL_WasInit(flags)) {
        fprintf(stderr, "\nCall to init_graphics with at least one flag already initialized\n");
        graphics_error_quit();
    } else {
    
        SDL_SetMainReady();
        
        if (SDL_Init(flags) == -1) {
            fprintf(stderr, "\nUnable to initialize SDL: %s\n", SDL_GetError());
            graphics_error_quit();
        }
        
        IMG_Init(IMG_INIT_JPG);
    }
    
}

void graphics_quit() {
    IMG_Quit();
    SDL_Quit();
}
