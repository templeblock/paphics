#ifndef DEF_GRAPHICS_H
#define DEF_GRAPHICS_H

#include <stdio.h>
#include <stdarg.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "point.h"

void graphics_error_quit();

void graphics_init(Uint32 flags);

void graphics_quit();

Point graphics_get_screen_size();

SDL_Color graphics_translate_color(Uint32 int_color);

#endif
