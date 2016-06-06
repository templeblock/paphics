#include "error.h"

void error_quit() {
    IMG_Quit();
    SDL_Quit();
    exit(EXIT_FAILURE);
}
