/**
 * \file sound.h
 * \brief Everything related to Sound.
 */

#ifndef DEF_SOUND_H
#define DEF_SOUND_H

#include <SDL2/SDL_mixer.h>
#include "error.h"

/**
 * \struct Sound
 * \brief A struct used to store a sound.
 */
typedef struct {
    Mix_Music* content; /*!< Pointer to the Mix_Music used to store the sound's content. */
} Sound;

/**
 * \fn void sound_load(const char* pathToFile, Sound* sound)
 * \brief Function to load a sound into a Sound struct.
 *
 * \param pathToFile The path to the file to load.
 * \param sound Pointer to the Sound in which the file must be stored.
 */
void sound_load(const char* pathToFile, Sound* sound);

/**
 * \fn void sound_play(const Sound* music)
 * \brief Function to play a sound indefinitely.
 *
 * \param music A pointer to the Sound to play.
 */
void sound_play(const Sound* music);

/**
 * \fn void sound_play_once(const Sound* music)
 * \brief Function to play a sound once.
 *
 * \param music A pointer to the Sound to play.
 */
void sound_play_once(const Sound* music);

/**
 * \fn void sound_free(Sound* sound)
 * \brief Function to free a Sound, i.e. to unload it.
 *
 * \param sound A pointer to the Sound to free.
 */
void sound_free(Sound* sound);

/**
 * \fn void sound_stop(void)
 * \brief Function to stop the current played Sound.
 */
void sound_stop(void);

/**
 * \fn void sound_pause(void)
 * \brief Function to pause the current played Sound.
 */
void sound_pause(void);

/**
 * \fn void sound_resume(void)
 * \brief Function to resume the current paused Sound.
 */
void sound_resume(void);

#endif
