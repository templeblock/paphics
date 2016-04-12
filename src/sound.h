#ifndef DEF_SOUND_H
#define DEF_SOUND_H

#include <SDL2/SDL_mixer.h>
#include "graphics.h"

typedef struct {
    Mix_Music* sound;
} Sound;

// initialise le son
void init_sound();

// charge un son
void load_sound(char* nomFichier, Sound* sound);

// joue indéfiniment une musique
void play_music(Sound* music);

// libère la place prise par la musique et ferme l'audio
void quit_mixer_SDL(Sound* sound);

#endif
