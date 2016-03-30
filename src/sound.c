#include "sound.h"

void init_sound() {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0) {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error:: %s", Mix_GetError());
        error_quit();
    }
}

void load_sound(char* nomFichier, Mix_Music* sound) {

    sound = NULL;

    sound = Mix_LoadMUS(nomFichier);

    if (sound == NULL) {
        fprintf(stderr, "Failed to load sound! SDL_mixer Error: %s\n", SDL_GetError());
        error_quit();
    }
}

void play_music(Mix_Music* music) {
    // on joue infiniment la musique
    Mix_PlayMusic(music, -1);
}

void quit_mixer_SDL(Mix_Music* music) {
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}
