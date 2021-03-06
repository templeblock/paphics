/**
 * \file color.h
 * \brief Everything related to Color.
 */

#ifndef DEF_COLOR_H
#define DEF_COLOR_H

#include <SDL2/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Color
 * \brief A struct used to represent a RGBA color.
 */
#pragma pack(push, 1)
typedef struct {
    Uint32 rgb;  /*!< Uint32 representing the RGB component of the color. */
    Uint8 alpha;  /*!< Uint8 representing the alpha component of the color. */
} Color;
#pragma pack(pop)

/**
 * \fn Uint8 color_get_red(const Color* color)
 * \brief Function to get the red component of a Color.
 *
 * \param color A pointer to the Color.
 * \return The red component in a Uint8.
 */
Uint8 color_get_red(const Color* color);

/**
 * \fn Uint8 color_get_green(const Color* color)
 * \brief Function to get the green component of a Color.
 *
 * \param color A pointer to the Color.
 * \return The green component in a Uint8.
 */
Uint8 color_get_green(const Color* color);

/**
 * \fn Uint8 color_get_blue(const Color* color)
 * \brief Function to get the blue component of a Color.
 *
 * \param color A pointer to the Color.
 * \return The blue component in a Uint8.
 */
Uint8 color_get_blue(const Color* color);

#ifdef __cplusplus
}
#endif

#endif
