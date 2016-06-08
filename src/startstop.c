#include "startstop.h"

void graphics_start(Uint32 flags) {

    if (SDL_WasInit(flags)) {
        fprintf(stderr, "\nCall to init_graphics with at least one flag already initialized\n");
        error_quit();
    } else {
    
        if (SDL_Init(flags) == -1) {
            fprintf(stderr, "\nUnable to initialize SDL: %s\n", SDL_GetError());
            error_quit();
        }
        
        const int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
        
        if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
            fprintf(stderr, "\nUnable to initialize SDL_IMAGE: %s\n", IMG_GetError());
            error_quit();
        }
    }
    
}

void graphics_stop() {
    IMG_Quit();
    SDL_Quit();
}
