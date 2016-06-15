#ifndef DEF_SOUND_H
#define DEF_SOUND_H

#include <SDL2/SDL_mixer.h>
#include "error.h"

typedef struct {
    Mix_Music* content;
} Sound;

void sound_load(const char* fileName, Sound* sound);

void sound_play(const Sound* music);

void sound_play_once(const Sound* music);

void sound_free(Sound* sound);

#endif
