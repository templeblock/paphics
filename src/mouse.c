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
    bool isHidden;
    
    mouseStatus = SDL_ShowCursor(-1);
    
    if (mouseStatus < 0) {
        fprintf(stderr, "mouse_is_hidden failed: %s\n", SDL_GetError());
        error_quit();
        isHidden = false; // useless, but otherwise, gcc thinks it may be used unitialized
    } else if (mouseStatus == 0) {
        isHidden = true;
    } else {
        isHidden = false;
    }
    
    return isHidden;
}

bool mouse_is_shown(void) {

    bool isShown;
    
    isShown = !mouse_is_hidden();
    
    return isShown;
}
