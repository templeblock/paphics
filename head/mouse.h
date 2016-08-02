/**
 * \file mouse.h
 * \brief Everything related to the mouse.
 */

#ifndef DEF_MOUSE_H
#define DEF_MOUSE_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "error.h"
#include "point.h"
#include "window.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \fn void mouse_hide(void)
 * \brief Function to hide the mouse cursor.
 */
void mouse_hide(void);

/**
 * \fn void mouse_show(void)
 * \brief Function to show the mouse cursor.
 */
void mouse_show(void);

/**
 * \fn void mouse_wait_click(const Window* window, Point* click)
 * \brief Function to wait a click and store it into a Point.
 *
 * \param window A pointer to the Window on which the click is waited.
 * \param click A pointer to the Point on which the click position must be stored.
 */
void mouse_wait_click(const Window* window, Point* click);

/**
 * \fn bool mouse_is_hidden(void)
 * \brief Function to know if the cursor is hidden.
 *
 * \return Returns true if the cursor is hidden, false otherwise.
 */
bool mouse_is_hidden(void);

/**
 * \fn bool mouse_is_shown(void)
 * \brief Function to know if the cursor is shown.
 *
 * \return Returns true if the cursor is shown, false otherwise.
 */
bool mouse_is_shown(void);

#ifdef __cplusplus
}
#endif

#endif
