#ifndef DEF_COLOR_H
#define DEF_COLOR_H

#include <SDL2/SDL.h>

#pragma pack(push, 1)
typedef struct {
    Uint32 rgb;
    Uint8 alpha;
} Color;
#pragma pack(pop)

void color_translate(const Color* color, SDL_Color* sdlColor);

Uint8 color_get_red(const Color* color) __attribute__((const));

Uint8 color_get_green(const Color* color) __attribute__((const));

Uint8 color_get_blue(const Color* color) __attribute__((pure));

#endif
