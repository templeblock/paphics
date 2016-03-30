#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H

#include <SDL2/SDL.h>
#include "surface.h"
#include "graphics.h"
#include "point.h"

typedef struct {
    Surface surface;
    SDL_Window* window;
    char* title;
    Point position;
    Point size;
} Window;

void load_window_img(Window window, char* pathToImg);

void update_window(Window window);

Window clear_window(Window window);

Window create_window(char* title, Point position, Point size, Uint32 flags);

Window destroy_window(Window window);

#endif
