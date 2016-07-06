/**
 * \file circle.h
 * \brief Everything related to Circle.
 */

#ifndef DEF_CIRCLE_H
#define DEF_CIRCLE_H

#include "pixel.h"

/**
 * \struct Circle
 * \brief A struct used to represent a circle.
 */
#pragma pack(push, 1)
typedef struct {
    Point center; /*!< Point representing the center of the circle, must be relative to its Canvas. */
    int radius; /*!< int representing the radius of the circle. */
    Canvas* canvas; /*!< Pointer to the Canvas the Circle belongs to. */
} Circle;
#pragma pack(pop)

/**
 * \fn void circle_draw(const Circle* circle, const Color* color)
 * \brief Function to draw a Circle.
 *
 * \param circle A pointer to the Circle to draw.
 * \param color A pointer to the Color to use to draw the Circle.
 */
void circle_draw(const Circle* circle, const Color* color);

/**
 * \fn void circle_draw_fill(const Circle* circle, const Color* color)
 * \brief Function to draw a filled Circle.
 *
 * \param circle A pointer to the Circle to draw.
 * \param color A pointer to the Color to use to draw the Circle.
 */
void circle_draw_fill(const Circle* circle, const Color* color);

#endif
