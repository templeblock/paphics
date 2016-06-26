#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H

#include "error.h"
#include "point.h"

typedef struct {
    SDL_Window* window;
    char* title;
    Point position;
    Point size;
} Window;

void window_create(Window* window, char* title, const Point* position, const Point* size, const Uint32 flags);

void window_destroy(Window* window);

void window_update(Window* window);

#endif
