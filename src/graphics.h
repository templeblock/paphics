#ifndef DEF_GRAPHICS_H
#define DEF_GRAPHICS_H

#include <stdio.h>
#include <stdarg.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void error_quit();

void init_graphics(Uint32 flags);

void quit_graphics();

SDL_Color translate_color(Uint32 int_color);

#endif
