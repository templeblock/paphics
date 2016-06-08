#include "startstop.h"

void graphics_start(Uint32 flags) {

    if (SDL_WasInit(flags)) {
        fprintf(stderr, "\nCall to init_graphics with at least one flag already initialized\n");
        error_quit();
    } else {
    
        SDL_SetMainReady();
        
        if (SDL_Init(flags) == -1) {
            fprintf(stderr, "\nUnable to initialize SDL: %s\n", SDL_GetError());
            error_quit();
        }
        
        IMG_Init(IMG_INIT_JPG);
    }
    
}

void graphics_stop() {
    IMG_Quit();
    SDL_Quit();
}
