#ifndef DEF_SURFACE_H
#define DEF_SURFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "window.h"
#include "point.h"

typedef struct {
    SDL_Surface* surface;
    Point size;
    Point origin;
    void* parent;
} Surface;

#include "rectangle.h"

void surface_blit(Surface* surface);

void surface_create(Surface* surface, Point* size, Point* origin, Surface* parent);

void surface_clear(Surface* surface);

void surface_create_from_window(Surface* surface, Window* window);

void surface_draw_borders_in(Surface* surface, Uint32 color);

void surface_draw_borders_out(Surface* surface, Uint32 color);

void surface_load_img(Surface* surface, char* pathToImg);

#endif
