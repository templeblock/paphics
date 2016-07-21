#include "mouse.h"

void mouse_hide() {

    if (SDL_ShowCursor(0) < 0) {
        fprintf(stderr, "mouse_hide failed: %s\n", SDL_GetError());
        error_quit();
    }
}

void mouse_show(void) {
    if (SDL_ShowCursor(1) < 0) {
        fprintf(stderr, "mouse_show failed: %s\n", SDL_GetError());
        error_quit();
    }
}

bool mouse_is_hidden(void) {

    int mouseStatus;

    mouseStatus = SDL_ShowCursor(-1);

    if (mouseStatus < 0) {
        fprintf(stderr, "mouse_is_hidden failed: %s\n", SDL_GetError());
        error_quit();
    }

    return (mouseStatus == 0 ? true : false);
}

bool mouse_is_shown(void) {

    bool isShown;

    isShown = !mouse_is_hidden();

    return isShown;
}

void mouse_wait_click(const Window* window, Point* click) {

    bool wait;
    wait = true;

    SDL_Event input;

    while (SDL_WaitEvent(&input) && wait) {
        if (input.type == SDL_MOUSEBUTTONDOWN && input.button.button == SDL_BUTTON_LEFT) {
            wait = false;
            click->x = input.button.x;
            click->y = window->size.y - input.button.y - 1; // not sure the -1 is correct here
        }
    }

}
