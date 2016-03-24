#include "main.h"

int main() {

    demo();

    return 0;
}

void demo() {

    SDL_Window *sdlWindow;
    SDL_Renderer *sdlRenderer;
    SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &sdlWindow, &sdlRenderer);

}
