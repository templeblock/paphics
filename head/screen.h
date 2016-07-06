/**
 * \file screen.h
 * \brief Everything related to the screen.
 */

#ifndef DEF_SCREEN_H
#define DEF_SCREEN_H

#include "error.h"
#include "point.h"

/**
 * \fn void screen_get_size(Point* screenSize)
 * \brief Function to get the screen's size.
 *
 * \param screenSize A pointer to the Point in which the screen's size must be stored.
 */
void screen_get_size(Point* screenSize);

#endif
