/**
 * \file error.h
 * \brief Everything related to errors and warnings handling.
 */

#ifndef DEF_ERROR_H
#define DEF_ERROR_H

#include <SDL2/SDL_image.h>
#include "startstop.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \fn void error_quit(void) __attribute__ ((noreturn))
 * \brief Function to quit after an error, will stop paphics and SDL components and stop the program.
 */
void error_quit(void) __attribute__ ((noreturn));

#ifdef __cplusplus
}
#endif

#endif
