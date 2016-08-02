/**
 * \file line.h
 * \brief Everything related to Line.
 */

#ifndef DEF_LINE_H
#define DEF_LINE_H

#include "pixel.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Line
 * \brief A struct used to represent a line segment.
 */
typedef struct {
    Point a; /*!< The first point of the line segment. */
    Point b; /*!< The last point of the line segment. */
    Canvas* canvas; /*!< The Canvas the Line belongs to. */
} Line;

/**
 * \fn void line_draw(const Line* line, const Color* color)
 * \brief Function to draw a line. The best one.
 *
 * \param line A pointer to the Line to draw.
 * \param color A pointer to the Color to use to draw the Line.
 */
void line_draw(const Line* line, const Color* color);

/**
 * \fn void line_draw_bis(const Line* line, const Color* color)
 * \brief Function to draw a line. Use floats and thus, is slower than line_draw.
 *
 * \param line A pointer to the Line to draw.
 * \param color A pointer to the Color to use to draw the Line.
 */
void line_draw_bis(const Line* line, const Color* color);

/**
 * \fn void line_draw_ter(const Line* line, const Color* color)
 * \brief Function to draw a line. Is very fast, but, draws lines with blanks.
 *
 * \param line A pointer to the Line to draw.
 * \param color A pointer to the Color to use to draw the Line.
 */
void line_draw_ter(const Line* line, const Color* color);

#ifdef __cplusplus
}
#endif

#endif
