#include "startstop.h"

void graphics_start(Uint32 flags) {

    if (SDL_WasInit(flags)) {
        fprintf(stderr, "\nCall to init_graphics with at least one flag already initialized\n");
        error_quit();
    } else {
        start_SDL(flags);
        start_SDL_image();
        start_SDL_mixer();
    }
}

void graphics_stop() {
    IMG_Quit();
    SDL_Quit();
    Mix_CloseAudio();
}

void start_SDL(Uint32 flags) {

    if (SDL_Init(flags) == -1) {
        fprintf(stderr, "\nUnable to initialize SDL: %s\n", SDL_GetError());
        error_quit();
    }
}

void start_SDL_image() {

    const int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    
    if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
        fprintf(stderr, "\nUnable to initialize SDL_IMAGE: %s\n", IMG_GetError());
        error_quit();
    }
}

void start_SDL_mixer() {

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) != 0) {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error:: %s", Mix_GetError());
        error_quit();
    }
}
