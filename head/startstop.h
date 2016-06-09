#ifndef DEF_STARTSTOP_H
#define DEF_STARTSTOP_H

#include <SDL2/SDL_mixer.h>
#include "error.h"

void graphics_start(Uint32 flags);

void graphics_stop(void);

void start_SDL(Uint32 flags);

void start_SDL_image(void);

void start_SDL_mixer(void);

#endif
