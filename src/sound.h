#include "graphics.h"
#include <SDL2/SDL_mixer.h>

// initialise le son
void init_sound();

// charge un son
void load_sound(char* nomFichier, Mix_Music* sound);

// joue indéfiniment une musique
void play_music(Mix_Music* music);

// libère la place prise par la musique et ferme l'audio
void quit_mixer_SDL(Mix_Music* music);
