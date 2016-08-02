/**
 * \file canvas.h
 * \brief Everything related to Canvas.
 */

#ifndef DEF_CANVAS_H
#define DEF_CANVAS_H

#include "window.h"
#include "color.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Canvas
 * \brief A Canvas is part of a Window or of another Canvas, on which it's possible to draw.
 */
typedef struct Canvas {
    SDL_Surface* surface; /*!< Pointer to the SDL_Surface used to store the content of the Canvas, user shouldn't have to touch this. */
    Point size; /*!< Point representing the size of the Canvas, usefull to get the value quickly, but user souldn't change it. */
    Point origin; /*!< Point representing the origin of the Canvas, user can set and get it safely. */
    struct Canvas* parent; /*!< Pointer to the Canvas representing the parent of the Canvas, i.e. the one on which it will be blitted. If the Canvas is the root Canvas representing the whole Window, then it points to NULL. */
} Canvas;

#include "rectangle.h"

/**
 * \fn bool canvas_collision_canvas(const Canvas* canvas1, const Canvas* canvas2) __attribute__((pure))
 * \brief Function to detect collision between two Canvas.
 *
 * \param canvas1 A pointer to the first Canvas.
 * \param canvas2 A pointer to the second Canvas.
 * \return If the two Canvas collide returns true, else, returns false.
 */
bool canvas_collision_canvas(const Canvas* canvas1, const Canvas* canvas2) __attribute__((pure));

/**
 * \fn bool canvas_contains_point(const Canvas* canvas, const Point point)
 * \brief Function to know if a Canvas contains a Point
 *
 * \param canvas A pointer to the Canvas.
 * \param point The Point.
 * \return True if the Canvas contains the Point, false otherwise.
 */
bool canvas_contains_point(const Canvas* canvas, const Point point);

/**
 * \fn bool canvas_is_out_of_parent_bottom(const Canvas* canvas) __attribute__((pure))
 * \brief Function to know if a Canvas is under its parent.
 *
 * \param canvas A pointer to the Canvas.
 * \return If the Canvas is under its parent, returns true, else, returns false.
 */
bool canvas_is_out_of_parent_bottom(const Canvas* canvas) __attribute__((pure));

/**
 * \fn bool canvas_is_out_of_parent_left(const Canvas* canvas) __attribute__((pure))
 * \brief Function to know if a Canvas is out of its parent's left side.
 *
 * \param canvas A pointer to the Canvas.
 * \return If the Canvas is out of its parent's left side, returns true, else, returns false.
 */
bool canvas_is_out_of_parent_left(const Canvas* canvas) __attribute__((pure));

/**
 * \fn bool canvas_is_out_of_parent_right(const Canvas* canvas) __attribute__((pure))
 * \brief Function to know if a Canvas is out of its parent's right side.
 *
 * \param canvas A pointer to the Canvas.
 * \return If the Canvas is out of its parent's right side, returns true, else, returns false.
 */
bool canvas_is_out_of_parent_right(const Canvas* canvas) __attribute__((pure));

/**
 * \fn bool canvas_is_out_of_parent_top(const Canvas* canvas) __attribute__((pure))
 * \brief Function to know if a Canvas is upper its parent's.
 *
 * \param canvas A pointer to the Canvas.
 * \return If the canvas is upper, returns true, else, returns false.
 */
bool canvas_is_out_of_parent_top(const Canvas* canvas) __attribute__((pure));

/**
 * \fn bool canvas_is_out_of_parent_x(const Canvas* canvas) __attribute__((pure))
 * \brief Function to know if a Canvas is outside of its parent's on the X axis.
 *
 * \param canvas A pointer to the Canvas.
 * \return If the Canvas is outside, returns true, else, returns false.
 */
bool canvas_is_out_of_parent_x(const Canvas* canvas) __attribute__((pure));

/**
 * \fn bool canvas_is_out_of_parent_y(const Canvas* canvas) __attribute__((pure))
 * \brief Function to know if a Canvas is outside of its parent's on the Y axis.
 *
 * \param canvas A pointer to the Canvas.
 * \return If the Canvas is outside, returns true, else, returns false.
 */
bool canvas_is_out_of_parent_y(const Canvas* canvas) __attribute__((pure));

/**
 * \fn bool canvas_will_be_out_of_parent_bottom(const Canvas* canvas, const Point* move) __attribute__((pure))
 * \brief Function to know if a Canvas will be under its parent after moving its origin.
 *
 * \param canvas A pointer to the Canvas.
 * \param move A pointer to the Point representing the origin's move.
 * \return If the Canvas will be under its parent, returns true, else, returns false.
 */
bool canvas_will_be_out_of_parent_bottom(const Canvas* canvas, const Point* move) __attribute__((pure));

/**
 * \fn bool canvas_will_be_out_of_parent_left(const Canvas* canvas, const Point* move) __attribute__((pure))
 * \brief Function to know if a Canvas will be out of its parent's left side after moving its origin.
 *
 * \param canvas A pointer to the Canvas.
 * \param move A pointer to the Point representing the origin's move.
 * \return If the Canvas will be will be out of its parent's left side, returns true, else, returns false.
 */
bool canvas_will_be_out_of_parent_left(const Canvas* canvas, const Point* move) __attribute__((pure));

/**
 * \fn bool canvas_will_be_out_of_parent_right(const Canvas* canvas, const Point* move) __attribute__((pure))
 * \brief Function to know if a Canvas will be out of its parent's right side after moving its origin.
 *
 * \param canvas A pointer to the Canvas.
 * \param move A pointer to the Point representing the origin's move.
 * \return If the Canvas will be will be out of its parent's right side, returns true, else, returns false.
 */
bool canvas_will_be_out_of_parent_right(const Canvas* canvas, const Point* move) __attribute__((pure));

/**
 * \fn bool canvas_will_be_out_of_parent_top(const Canvas* canvas, const Point* move) __attribute__((pure))
 * \brief Function to know if a Canvas will be upper its parent after moving its origin.
 *
 * \param canvas A pointer to the Canvas.
 * \param move A pointer to the point representing the origin's move.
 * \return If the Canvas will be upper its parent, returns true, else, returns false.
 */
bool canvas_will_be_out_of_parent_top(const Canvas* canvas, const Point* move) __attribute__((pure));

/**
 * \fn bool canvas_will_be_out_of_parent_x(const Canvas* canvas, const Point* move) __attribute__((pure))
 * \brief Function to know if a Canvas will be outside of its parent on the X axis after moving its origin.
 *
 * \param canvas A pointer to the Canvas.
 * \param move A pointer to the point representing the origin's move.
 * \return If the Canvas will be outside of its parent on the X axis, returns true, else, returns false.
 */
bool canvas_will_be_out_of_parent_x(const Canvas* canvas, const Point* move) __attribute__((pure));

/**
 * \fn bool canvas_will_be_out_of_parent_y(const Canvas* canvas, const Point* move) __attribute__((pure))
 * \brief Function to know if a Canvas will be outside of its parent on the Y axis after moving its origin.
 *
 * \param canvas A pointer to the Canvas.
 * \param move A pointer to the point representing the origin's move.
 * \return If the Canvas will be outside of its parent on the Y axis, returns true, else, returns false.
 */
bool canvas_will_be_out_of_parent_y(const Canvas* canvas, const Point* move) __attribute__((pure));

/**
 * \fn Point canvas_get_absolute_origin(const Canvas* canvas)
 * \brief Function to get the origin of a Canvas on the Window, instead of on its parent.
 *
 * \param canvas A pointer to the Canvas.
 * \return A Point in which the absolute origin is stored.
 */
Point canvas_get_absolute_origin(const Canvas* canvas);

/**
 * \fn Point canvas_get_bottom_left_corner(const Canvas* canvas)
 * \brief Function to get the bottom left corner of a Canvas
 *
 * \param canvas The Canvas.
 * \return A Point representing the bottom left corner of the Canvas.
 */
Point canvas_get_bottom_left_corner(const Canvas* canvas);

/**
 * \fn Point canvas_get_bottom_right_corner(const Canvas* canvas)
 * \brief Function to get the bottom right corner of a Canvas
 *
 * \param canvas The Canvas.
 * \return A Point representing the bottom right corner of the Canvas.
 */
Point canvas_get_bottom_right_corner(const Canvas* canvas);

/**
 * \fn Point canvas_get_top_left_corner(const Canvas* canvas)
 * \brief Function to get the top left corner of a Canvas
 *
 * \param canvas The Canvas.
 * \return A Point representing the top left corner of the Canvas.
 */
Point canvas_get_top_left_corner(const Canvas* canvas);

/**
 * \fn Point canvas_get_top_right_corner(const Canvas* canvas)
 * \brief Function to get the top right corner of a Canvas
 *
 * \param canvas The Canvas.
 * \return A Point representing the top right corner of the Canvas.
 */
Point canvas_get_top_right_corner(const Canvas* canvas);

/**
 * \fn void canvas_blit(Canvas* canvas)
 * \brief Function to blit a Canvas on its parent.
 *
 * \param canvas A pointer to the Canvas to blit.
 */
void canvas_blit(Canvas* canvas);

/**
 * \fn void canvas_create(Canvas* canvas, const Point* size, const Point* origin, Canvas* parent)
 * \brief Function to create a Canvas.
 *
 * \param canvas A pointer to the Canvas to create.
 * \param size A pointer to a Point representing the wanted size for the Canvas.
 * \param origin A pointer to a Point representing the wanted origin for the Canvas.
 * \param parent A pointer to the Canvas wanted as the parent of the Canvas to create.
 */
void canvas_create(Canvas* canvas, const Point* size, const Point* origin, Canvas* parent);

/**
 * \fn void canvas_clear(Canvas* canvas)
 * \brief Function to clear a Canvas, i.e. filling it with black.
 *
 * \param canvas A pointer to the Canvas to clear.
 */
void canvas_clear(Canvas* canvas);

/**
 * \fn void canvas_create_from_window(Canvas* canvas, const Window* window)
 * \brief Function to create a Canvas from a Window, it will fill the whole window.
 *
 * \param canvas A pointer to the Canvas to create.
 * \param window A pointer to the Window from which the Canvas should be created.
 */
void canvas_create_from_window(Canvas* canvas, const Window* window);

/**
 * \fn void canvas_draw_borders_in(Canvas* canvas, const Color* color)
 * \brief Function to draw a 1 pixel border inside of a Canvas.
 *
 * \param canvas A pointer to the Canvas.
 * \param color A pointer to the Color wanted for the border.
 */
void canvas_draw_borders_in(Canvas* canvas, const Color* color);

/**
 * \fn void canvas_draw_borders_out(Canvas* canvas, const Color* color)
 * \brief Function to draw a 1 pixel border outside of a Canvas.
 *
 * \param canvas A pointer to the Canvas.
 * \param color A pointer to the Color wanted for the border.
 */
void canvas_draw_borders_out(Canvas* canvas, const Color* color);

/**
 * \fn void canvas_fill(Canvas* canvas, const Color* color)
 * \brief Function to fill a Canvas with a Color.
 *
 * \param canvas A pointer to the Canvas to fill.
 * \param color A pointer to the Color wanted to fill the Canvas.
 */
void canvas_fill(Canvas* canvas, const Color* color);

#ifdef __cplusplus
}
#endif

#endif
