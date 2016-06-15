#include "sound.h"

void sound_load(const char* fileName, Sound* sound) {

    sound->content = NULL;
    
    sound->content = Mix_LoadMUS(fileName);
    
    if (sound->content == NULL) {
        fprintf(stderr, "Failed to load sound! SDL_mixer Error: %s\n", SDL_GetError());
        error_quit();
    }
}

void sound_play(const Sound* sound) {
    Mix_PlayMusic(sound->content, -1);
}

void sound_play_once(const Sound* sound) {
    Mix_PlayMusic(sound->content, 1);
}

void sound_free(Sound* sound) {
    Mix_FreeMusic(sound->content);
}
