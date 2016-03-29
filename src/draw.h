#ifndef DEF_DRAW_H
#define DEF_DRAW_H

#include <SDL2/SDL.h>
#include "graphics.h"
#include "surface.h"
#include "point.h"
#include "pixel.h"

void draw(Surface surface, ...);

void draw_circle(Surface surface, Point center, int radius, Uint32 color);

void draw_fill_circle(Surface surface, Point center, int radius, Uint32 color);

void draw_fill_rectangle(Surface surface, Point a, Point b, Uint32 color);

void draw_fill_sphere(Surface surface, Point center, int radius, Uint32 originalColor);

void draw_line(Surface surface, Point a, Point b, Uint32 color);

void draw_pixel(Surface surface, Pixel pixel);

void draw_rectangle(Surface surface, Point a, Point b, Uint32 color);

#endif
