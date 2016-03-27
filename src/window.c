#include "window.h"

void load_window_img(Window window, char* pathToImg) {

    load_surface_img(window.surface, pathToImg);
}

void update_window(Window window) {

    SDL_UpdateWindowSurface(window.window);
}

Window clear_window(Window window) {

    SDL_FillRect(window.surface.surface, NULL, SDL_MapRGB(window.surface.surface->format, 0x00, 0x00, 0x00));

    return window;
}

Window create_window(char* title, Point position, Point size) {

    Window newWindow;

    newWindow.title = title;
    newWindow.position = position;
    newWindow.size = size;
    newWindow.window = NULL;

    newWindow.window = SDL_CreateWindow(title, position.x, position.y, size.x, size.y, SDL_WINDOW_SHOWN);

    if (newWindow.window == NULL) {
        fprintf(stderr, "\nWindow could not be created! SDL_Error: %s\n", SDL_GetError());
        error_quit();
    }

    newWindow.surface.surface = NULL;

    newWindow.surface.surface = SDL_GetWindowSurface(newWindow.window);

    if (newWindow.surface.surface == NULL) {
        fprintf(stderr, "\nWindow's surface could not be loaded! SDL_Error: %s\n", SDL_GetError());
        error_quit();
    }

    newWindow.surface.size = size;

    SDL_FillRect(newWindow.surface.surface, NULL, SDL_MapRGB(newWindow.surface.surface->format, 0x00, 0x00, 0x00));

    return newWindow;
}

Window destroy_window(Window window) {

    SDL_FreeSurface(window.surface.surface);
    window.surface.surface = NULL;

    SDL_DestroyWindow(window.window);
    window.window = NULL;

    return window;
}
