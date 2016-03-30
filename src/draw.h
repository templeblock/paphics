#ifndef DEF_DRAW_H
#define DEF_DRAW_H

#include <SDL2/SDL.h>
#include "graphics.h"
#include "surface.h"
#include "point.h"
#include "pixel.h"
#include "sphere.h"
#include "line.h"

void draw(Surface surface, ...);

void draw_borders_in(Surface surface, Uint32 color);

void draw_borders_out(Surface surface, Uint32 color);

void draw_circle(Surface surface, Point center, int radius, Uint32 color);

void draw_fill_circle(Surface surface, Point center, int radius, Uint32 color);

void draw_fill_rectangle(Surface surface, Point a, Point b, Uint32 color);

void draw_fill_sphere(Surface surface, Sphere* sphere);

void draw_line(Surface surface, Line* line);

void draw_pixel(Surface surface, Pixel* pixel);

void draw_rectangle(Surface surface, Point a, Point b, Uint32 color);

#endif
