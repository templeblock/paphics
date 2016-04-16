#ifndef DEF_SURFACE_H
#define DEF_SURFACE_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "window.h"
#include "point.h"

typedef struct Surface {
    SDL_Surface* surface;
    Point size;
    Point origin;
    struct Surface* parent;
} Surface;

#include "rectangle.h"

bool surface_is_out_of_parent_bottom(Surface* surface);

bool surface_is_out_of_parent_left(Surface* surface);

bool surface_is_out_of_parent_right(Surface* surface);

bool surface_is_out_of_parent_top(Surface* surface);

bool surface_is_out_of_parent_x(Surface* surface);

bool surface_is_out_of_parent_y(Surface* surface);

bool surface_will_be_out_of_parent_bottom(Surface* surface, Point* d);

bool surface_will_be_out_of_parent_left(Surface* surface, Point* d);

bool surface_will_be_out_of_parent_right(Surface* surface, Point* d);

bool surface_will_be_out_of_parent_top(Surface* surface, Point* d);

bool surface_will_be_out_of_parent_x(Surface* surface, Point* d);

bool surface_will_be_out_of_parent_y(Surface* surface, Point* d);

void surface_blit(Surface* surface);

void surface_create(Surface* surface, Point* size, Point* origin, Surface* parent);

void surface_clear(Surface* surface);

void surface_create_from_window(Surface* surface, Window* window);

void surface_draw_borders_in(Surface* surface, Uint32 color);

void surface_draw_borders_out(Surface* surface, Uint32 color);

void surface_load_img(Surface* surface, char* pathToImg);

#endif
