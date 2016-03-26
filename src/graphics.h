#ifndef DEF_GRAPHICS_H
#define DEF_GRAPHICS_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void error_quit();

void init_graphics(Uint32 flags);

void quit_graphics();

#endif
