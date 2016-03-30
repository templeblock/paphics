#include "window.h"

Surface get_window_surface(Window window) {

    Surface copyWindowSurface;

    copyWindowSurface.parent = NULL;
    copyWindowSurface.surface = window.surface.surface;
    copyWindowSurface.origin.x = 0;
    copyWindowSurface.origin.y = 0;
    copyWindowSurface.size.x = copyWindowSurface.surface->w;
    copyWindowSurface.size.y = copyWindowSurface.surface->h;

    return copyWindowSurface;

}

void update_window(Window window) {

    SDL_UpdateWindowSurface(window.window);
}

Window clear_window(Window window) {

    SDL_FillRect(window.surface.surface, NULL, 0x000000);

    return window;
}

Window create_window(char* title, Point position, Point size, Uint32 flags) {

    Window newWindow;

    newWindow.title = title;
    newWindow.position = position;
    newWindow.window = NULL;

    newWindow.window = SDL_CreateWindow(title, position.x, position.y, size.x, size.y, flags);

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
