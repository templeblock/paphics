/**
 * \file startstop.h
 * \brief Everything related to paphics' start and stop functions.
 */

#ifndef DEF_STARTSTOP_H
#define DEF_STARTSTOP_H

#include <SDL2/SDL_mixer.h>
#include "error.h"

/**
 * \fn void paphics_start(const Uint32 flags)
 * \brief Function to start paphics.
 *
 * \param flags A list of SDL flags, if you don't know, use SDL_INIT_EVERYTHING, or see SDL_Init doc.
 */
void paphics_start(const Uint32 flags);

/**
 * \fn void paphics_stop(void)
 * \brief Function to stop paphics.
 */
void paphics_stop(void);

#endif
