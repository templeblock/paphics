/**
 * \file pixel.h
 * \brief Everything related to Pixel.
 */

#ifndef DEF_PIXEL_H
#define DEF_PIXEL_H

#include "canvas.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Pixel
 * \brief A struct used to represent a pixel.
 */
typedef struct {
    Point position; /*!< Point representing the position of the Pixel. */
    Canvas* canvas; /*!< Pointer to the Canvas the Pixel belongs to. */
} Pixel;

/**
 * \fn void pixel_draw(const Pixel* pixel, const Color* color)
 * \brief Function to draw a pixel.
 *
 * \param pixel A pointer to the Pixel to draw.
 * \param color A pointer to the Color to use to draw the Pixel.
 */
void pixel_draw(const Pixel* pixel, const Color* color);

#ifdef __cplusplus
}
#endif

#endif
