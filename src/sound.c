#include "sound.h"

void sound_load(const char* pathToFile, Sound* sound) {

    sound->content = NULL;
    
    sound->content = Mix_LoadMUS(pathToFile);
    
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

void sound_stop() {
    Mix_HaltMusic();
}

void sound_pause() {
    Mix_Pause(-1);
}

void sound_resume() {
    Mix_Resume(-1);
}
