#include "sound.h"

void init_sound() {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0) {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error:: %s", Mix_GetError());
        graphics_error_quit();
    }
}

void load_sound(char* nomFichier, Sound* sound) {

    sound->sound = NULL;

    sound->sound = Mix_LoadMUS(nomFichier);

    if (sound->sound == NULL) {
        fprintf(stderr, "Failed to load sound! SDL_mixer Error: %s\n", SDL_GetError());
        graphics_error_quit();
    }
}

void play_music(Sound* music) {
    // on joue infiniment la musique
    Mix_PlayMusic(music->sound, -1);
}

void quit_mixer_SDL(Sound* sound) {
    Mix_FreeMusic(sound->sound);
    Mix_CloseAudio();
}
