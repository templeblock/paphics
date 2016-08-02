/**
 * \file image.h
 * \brief Everything related to Image.
 */

#ifndef DEF_IMAGE_H
#define DEF_IMAGE_H

#include "paphics.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Image
 * \brief A struct representing an image.
 */
typedef struct {
    SDL_Surface* surface; /*!< Pointer to the SDL_Surface used to store the content of the image, user shouldn't have to touch this. */
    Canvas* canvas; /*!< Pointer to the Canvas the Image belongs to. */
} Image;

/**
 * \fn void image_blit_naive(const Image* image)
 * \brief Function to blit an Image on its Canvas, it will be blitted "as is", even if the Image is bigger than its Canvas.
 *
 * \param image A pointer to the Image to blit.
 */
void image_blit_naive(const Image* image);

/**
 * \fn void image_blit_scaled(const Image* image)
 * \brief Function to blit an Image on its Canvas, it will be scaled, i.e. will fill the Canvas perfectly.
 *
 * \param image A pointer to the Image to blit.
 */
void image_blit_scaled(const Image* image);

/**
 * \fn void image_load(Image* image, const char* pathToImg)
 * \brief Function to load an image into an Image struct.
 *
 * \param image A pointer to the Image used to store the loaded image.
 * \param pathToImg The path to the image to load.
 */
void image_load(Image* image, const char* pathToImg);

/**
 * \fn void image_unload(Image* image)
 * \brief Function to unload an Image, i.e. to free it.
 *
 * \param image A pointer to the Image to unload.
 */
void image_unload(Image* image);

#ifdef __cplusplus
}
#endif

#endif
