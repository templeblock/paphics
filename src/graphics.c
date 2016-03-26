#include "graphics.h"

void error_quit() {
    IMG_Quit();
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void init_graphics(Uint32 flags) {

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

void quit_graphics() {
    IMG_Quit();
    SDL_Quit();
}
