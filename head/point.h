/**
 * \file point.h
 * \brief Everything related to Point.
 */

#ifndef DEF_POINT_H
#define DEF_POINT_H

#include <math.h>
#include <stdbool.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Point
 * \brief A struct used to represent a point.
 */
typedef struct {
    int x; /*!< The value of the point on the x-coordinate. */
    int y; /*!< The value of the point on the y-coordinate. */
} Point;

/**
 * \fn bool point_are_equals(const Point p1, const Point p2) __attribute__((const))
 * \brief Function to know if two Point are equals.
 *
 * \param p1 The first Point.
 * \param p2 The second Point.
 *
 * \return Return true if they're equals, false otherwise.
 */
bool point_are_equals(const Point p1, const Point p2) __attribute__((const));

/**
 * \fn int point_distance(const Point a, const Point b)
 * \brief Function to get the distance between two Point.
 *
 * \param a The first Point.
 * \param b The second Point.
 *
 * \return The distance between the two Point, in an int.
 */
int point_distance(const Point a, const Point b);

/**
 * \fn Point point_max_x(const Point a, const Point b)
 * \brief Function to compare two Point and getting the one with the biggest x.
 *
 * \param a The first Point.
 * \param b The second Point.
 *
 * \return The Point with the biggest x.
 */
Point point_max_x(const Point a, const Point b);

/**
 * \fn Point point_max_y(const Point a, const Point b)
 * \brief Function to compare two Point and getting the one with the biggest y.
 *
 * \param a The first Point.
 * \param b The second Point.
 *
 * \return The Point with the biggest y.
 */
Point point_max_y(const Point a, const Point b);

/**
 * \fn Point point_min_x(const Point a, const Point b)
 * \brief Function to compare two Point and getting the one with the smallest x.
 *
 * \param a The first Point.
 * \param b The second Point.
 *
 * \return The Point with the smallest x.
 */
Point point_min_x(const Point a, const Point b);

/**
 * \fn Point point_min_y(const Point a, const Point b)
 * \brief Function to compare two Point and getting the one with the smallest y.
 *
 * \param a The first Point.
 * \param b The second Point.
 *
 * \return The Point with the smallest y.
 */
Point point_min_y(const Point a, const Point b);

#ifdef __cplusplus
}
#endif

#endif
