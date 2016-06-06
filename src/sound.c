#include "sound.h"

void sound_init() {

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0) {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error:: %s", Mix_GetError());
        error_quit();
    }
}

void sound_load(char* nomFichier, Sound* sound) {

    sound->content = NULL;
    
    sound->content = Mix_LoadMUS(nomFichier);
    
    if (sound->content == NULL) {
        fprintf(stderr, "Failed to load sound! SDL_mixer Error: %s\n", SDL_GetError());
        error_quit();
    }
}

void sound_play(Sound* sound) {
    Mix_PlayMusic(sound->content, -1);
}

void sound_play_once(Sound* sound) {
    Mix_PlayMusic(sound->content, 1);
}

void sound_free(Sound* sound) {
    Mix_FreeMusic(sound->content);
}

void sound_quit() {
    Mix_CloseAudio();
}
