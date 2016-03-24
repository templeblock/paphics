#include "graphics.h"

void error_quit() {
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
    }

}
