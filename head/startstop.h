/**
 * \file startstop.h
 * \brief Everything related to graphics' start and stop functions.
 */

#ifndef DEF_STARTSTOP_H
#define DEF_STARTSTOP_H

#include <SDL2/SDL_mixer.h>
#include "error.h"

/**
 * \fn void graphics_start(const Uint32 flags)
 * \brief Function to start graphics.
 *
 * \param flags A list of SDL flags, if you don't know, use SDL_INIT_EVERYTHING, or see SDL_Init doc.
 */
void graphics_start(const Uint32 flags);

/**
 * \fn void graphics_stop(void)
 * \brief Function to stop graphics.
 */
void graphics_stop(void);

#endif
