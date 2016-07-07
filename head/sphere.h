/**
 * \file sphere.h
 * \brief Everything related to Sphere.
 */

#ifndef DEF_SPHERE_H
#define DEF_SPHERE_H

#include "circle.h"
#include "color.h"

/**
 * \struct Sphere
 * \brief A struct used to represent a sphere.
 */
#pragma pack(push, 1)
typedef struct {
    Point center; /*!< Point representing the center of the sphere, must be relative to its Canvas. */
    int radius; /*!< int representing the radius of the sphere. */
    Canvas* canvas; /*!< Pointer to the Canvas the Sphere belongs to. */
} Sphere;
#pragma pack(pop)

/**
 * \fn void sphere_draw_fill(const Sphere* sphere, const Color* color)
 * \brief Function to draw a filled Sphere.
 *
 * \param sphere A pointer to the Sphere to draw.
 * \param color A pointer to the Color to use to draw the Sphere.
 */
void sphere_draw_fill(const Sphere* sphere, const Color* color);

#endif
