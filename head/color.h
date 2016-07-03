#ifndef DEF_COLOR_H
#define DEF_COLOR_H

#include <SDL2/SDL.h>

void color_translate(const Uint32 int_color, SDL_Color* color);

Uint8 color_get_red(const Uint32 color) __attribute__((const));

Uint8 color_get_green(const Uint32 color) __attribute__((const));

Uint8 color_get_blue(const Uint32 color) __attribute__((const));

#endif
