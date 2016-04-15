#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H

#include <SDL2/SDL.h>
#include "graphics.h"
#include "point.h"

typedef struct {
    SDL_Window* window;
    char* title;
    Point position;
} Window;

void window_create(Window* window, char* title, Point* position, Point* size, Uint32 flags);

void window_destroy(Window* window);

void window_update(Window* window);

#endif
