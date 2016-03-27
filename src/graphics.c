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

SDL_Color translate_color(Uint32 int_color) {

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    SDL_Color color = {(int_color & 0x00ff0000) / 0x10000, (int_color &0x0000ff00) / 0x100, (int_color & 0x000000ff), 0};
#else
    SDL_Color color = {(int_color & 0x000000ff), (int_color &0x0000ff00) / 0x100, (int_color & 0x00ff0000) / 0x10000, 0};
#endif

    // shouldn't have to do this... would be good to find why
    color.r = 255 - color.r;
    color.g = 255 - color.g;
    color.b = 255 - color.b;

    return color;
}
