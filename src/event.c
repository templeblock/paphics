#include "event.h"

char event_wait_key() {

    SDL_Event tmp;
    char key = '\0';
    
    SDL_WaitEvent(&tmp);
    
    if (tmp.type == SDL_QUIT) {
        key = 27;
    } else if (tmp.type == SDL_KEYDOWN) {
        key = (char) tmp.key.keysym.sym;
    }
    
    return key;
}

void event_create(Event* newEvent) {

    newEvent->quit = false;
    newEvent->arrows.x = 0;
    newEvent->arrows.y = 0;
    newEvent->space = false;
}

void event_update(Event* event) {

    SDL_Event tmp;
    
    while (SDL_PollEvent(&tmp) != 0) {
        if (tmp.type == SDL_QUIT) {
            event->quit = true;
        } else if (tmp.type == SDL_KEYDOWN) {
            switch (tmp.key.keysym.sym) {
                case SDLK_UP:
                    event->arrows.y = 1;
                    break;
                    
                case SDLK_DOWN:
                    event->arrows.y = -1;
                    break;
                    
                case SDLK_LEFT:
                    event->arrows.x = -1;
                    break;
                    
                case SDLK_RIGHT:
                    event->arrows.x = 1;
                    break;
                    
                case SDLK_SPACE:
                    event->space = 1;
                    break;
                    
                case SDLK_ESCAPE:
                    event->quit = 1;
                    break;
                    
                default:
                    break;
            }
        } else if (tmp.type == SDL_KEYUP) {
        
            switch (tmp.key.keysym.sym) {
                case SDLK_UP:
                    event->arrows.y = 0;
                    
                //break;
                case SDLK_DOWN:
                    event->arrows.y = 0;
                    
                //break;
                case SDLK_LEFT:
                    event->arrows.x = 0;
                    
                //break;
                case SDLK_RIGHT:
                    event->arrows.x = 0;
                    
                //break;
                case SDLK_SPACE:
                    event->space = 0;
                    
                default:
                    break;
            }
        }
    }
}
