#include "screen.h"

void screen_get_size(Point* screenSize) {

    SDL_DisplayMode tmp;
    
    if (SDL_GetDesktopDisplayMode(0, &tmp) != 0) {
        fprintf(stderr, "\nSDL_GetDesktopDisplayMode failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }
    
    screenSize->x = tmp.w;
    screenSize->y = tmp.h;
    
}
