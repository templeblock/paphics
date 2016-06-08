#include "window.h"

void window_create(Window* window, char* title, Point* position, Point* size, Uint32 flags) {

    window->title = title;
    window->position = *position;
    window->window = NULL;
    
    window->window = SDL_CreateWindow(title, position->x, position->y, size->x, size->y, flags);
    
    if (window->window == NULL) {
        fprintf(stderr, "\nWindow could not be created! SDL_Error: %s\n", SDL_GetError());
        error_quit();
    }
    
}

void window_destroy(Window* window) {

    if (window->window == NULL) {
        fprintf(stderr, "\nWarning: trying to destroy a NULL window.\n");
    } else {
        SDL_DestroyWindow(window->window);
        window->window = NULL;
    }
}

void window_update(Window* window) {

    SDL_UpdateWindowSurface(window->window);
}
