/**
 * \file window.h
 * \brief Everything related to Window.
 */

#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H

#include "error.h"
#include "point.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Window
 * \brief A struct representing a window.
 */
typedef struct {
    SDL_Window* window; /*!< Pointer to the SDL_Window used to store the window. */
    char* title; /*!< The window's title. */
    Point position; /*!< Point representing the window's position. */
    Point size; /*!< Point representing the window's size. */
} Window;

/**
 * \fn void window_create(Window* window, char* title, const Point* position, const Point* size, const Uint32 flags)
 * \brief Function to create a Window.
 *
 * \param window A pointer to the Window in which the new Window will be stored.
 * \param title The title wanted for the Window.
 * \param position A pointer to a Point representing the position wanted for the Window.
 * \param size A pointer to a Point representing the size wanted for the Window.
 * \param flags A list of SDL flags, if you don't know, use SDL_WINDOW_SHOWN, or see SDL_CreateWindow doc.
 */
void window_create(Window* window, char* title, const Point* position, const Point* size, const Uint32 flags);

/**
 * \fn void window_destroy(Window* window)
 * \brief Function to destroy a Window
 *
 * \param window A pointer to the Window to destroy.
 */
void window_destroy(Window* window);

/**
 * \fn void window_update(Window* window)
 * \brief Function to update a Window
 *
 * \param window A pointer to the Window to update.
 */
void window_update(Window* window);

#ifdef __cplusplus
}
#endif

#endif
