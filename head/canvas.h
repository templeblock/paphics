#ifndef DEF_CANVAS_H
#define DEF_CANVAS_H

#include "window.h"

typedef struct Canvas {
    SDL_Surface* surface;
    Point size;
    Point origin;
    struct Canvas* parent;
} Canvas;

#include "rectangle.h"

bool canvas_collision_canvas(const Canvas* canvas1, const Canvas* canvas2);

bool canvas_is_out_of_parent_bottom(const Canvas* canvas);

bool canvas_is_out_of_parent_left(const Canvas* canvas);

bool canvas_is_out_of_parent_right(const Canvas* canvas);

bool canvas_is_out_of_parent_top(const Canvas* canvas);

bool canvas_is_out_of_parent_x(const Canvas* canvas);

bool canvas_is_out_of_parent_y(const Canvas* canvas);

bool canvas_will_be_out_of_parent_bottom(const Canvas* canvas, const Point* d);

bool canvas_will_be_out_of_parent_left(const Canvas* canvas, const Point* d);

bool canvas_will_be_out_of_parent_right(const Canvas* canvas, const Point* d);

bool canvas_will_be_out_of_parent_top(const Canvas* canvas, const Point* d);

bool canvas_will_be_out_of_parent_x(const Canvas* canvas, const Point* d);

bool canvas_will_be_out_of_parent_y(const Canvas* canvas, const Point* d);

void canvas_blit(Canvas* canvas);

void canvas_create(Canvas* canvas, const Point* size, const Point* origin, Canvas* parent);

void canvas_clear(Canvas* canvas);

void canvas_create_from_window(Canvas* canvas, const Window* window);

void canvas_draw_borders_in(Canvas* canvas, const Uint32 color);

void canvas_draw_borders_out(Canvas* canvas, const Uint32 color);

void canvas_fill(Canvas* canvas, const Uint32 color);

void canvas_get_absolute_origin(Canvas* canvas, Point* absoluteOrigin);

#endif
