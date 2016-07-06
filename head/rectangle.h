/**
 * \file point.h
 * \brief Everything related to Rectangle.
 */

#ifndef DEF_RECTANGLE_H
#define DEF_RECTANGLE_H

#include "point.h"
#include "line.h"
#include "color.h"

/**
 * \struct Rectangle
 * \brief A struct used to represent a rectanglec.
 */
typedef struct {
    Point origin; /*!< Point representing the origin of the Rectangle on its Canvas. */
    Point size; /*!< Point representing the size of the Canvas. */
    Canvas* canvas; /*!< Pointer to the Canvas the Rectangle belongs to. */
} Rectangle;

/**
 * \fn void rectangle_draw(const Rectangle* rectangle, const Color* color)
 * \brief Function to draw a Rectangle.
 *
 * \param circle A pointer to the Rectangle to draw.
 * \param color A pointer to the Color to use to draw the Rectangle.
 */
void rectangle_draw(const Rectangle* rectangle, const Color* color);

/**
 * \fn void rectangle_draw_fill(const Rectangle* rectangle, const Color* color)
 * \brief Function to draw a filled Rectangle.
 *
 * \param circle A pointer to the Rectangle to draw.
 * \param color A pointer to the Color to use to draw the Rectangle.
 */
void rectangle_draw_fill(const Rectangle* rectangle, const Color* color);

/**
 * \fn bool rectangle_contains_point(const Rectangle* rect, const Point* p) __attribute__((pure))
 * \brief Function to know if a rectangle contains a Point.
 *
 * \param rect A pointer to the Rectangle.
 * \param p A pointer to the Point.
 *
 * \return Returns true if the Rectangle contains the Point, false otherwise.
 */
bool rectangle_contains_point(const Rectangle* rect, const Point* p) __attribute__((pure));

/**
 * \fn bool rectangle_contains_absolute_point(const Rectangle* rect, const Point* p)
 * \brief Function to know if a rectangle contains a Point, when the point have absolute coordinates, i.e. relative to the current Window.
 *
 * \param rect A pointer to the Rectangle.
 * \param p A pointer to the Point.
 *
 * \return Returns true if the Rectangle contains the Point, false otherwise.
 */
bool rectangle_contains_absolute_point(const Rectangle* rect, const Point* p);

#endif
