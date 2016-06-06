#ifndef DEF_CANVAS_H
#define DEF_CANVAS_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "error.h"
#include "window.h"
#include "point.h"

typedef struct Canvas {
    SDL_Surface* surface;
    Point size;
    Point origin;
    struct Canvas* parent;
} Canvas;

#include "rectangle.h"

bool canvas_collision_canvas(Canvas* canvas1, Canvas* canvas2);

bool canvas_is_out_of_parent_bottom(Canvas* canvas);

bool canvas_is_out_of_parent_left(Canvas* canvas);

bool canvas_is_out_of_parent_right(Canvas* canvas);

bool canvas_is_out_of_parent_top(Canvas* canvas);

bool canvas_is_out_of_parent_x(Canvas* canvas);

bool canvas_is_out_of_parent_y(Canvas* canvas);

bool canvas_will_be_out_of_parent_bottom(Canvas* canvas, Point* d);

bool canvas_will_be_out_of_parent_left(Canvas* canvas, Point* d);

bool canvas_will_be_out_of_parent_right(Canvas* canvas, Point* d);

bool canvas_will_be_out_of_parent_top(Canvas* canvas, Point* d);

bool canvas_will_be_out_of_parent_x(Canvas* canvas, Point* d);

bool canvas_will_be_out_of_parent_y(Canvas* canvas, Point* d);

void canvas_blit(Canvas* canvas);

void canvas_create(Canvas* canvas, Point* size, Point* origin, Canvas* parent);

void canvas_clear(Canvas* canvas);

void canvas_create_from_window(Canvas* canvas, Window* window);

void canvas_draw_borders_in(Canvas* canvas, Uint32 color);

void canvas_draw_borders_out(Canvas* canvas, Uint32 color);

void canvas_load_img_naive(Canvas* canvas, char* pathToImg);

void canvas_load_img_scaled(Canvas* canvas, char* pathToImg);

#endif
