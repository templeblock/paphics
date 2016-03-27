#include "event.h"

Event create_event() {

    Event newEvent;

    newEvent.quit = false;
    newEvent.arrows.x = 0;
    newEvent.arrows.y = 0;

    return newEvent;
}

Event update_event(Event event) {

    SDL_Event tmp;

    while (SDL_PollEvent(&tmp) != 0) {
        if (tmp.type == SDL_QUIT) {
            event.quit = true;
        } else if (tmp.type == SDL_KEYDOWN) {
            switch (tmp.key.keysym.sym) {
            case SDLK_UP:
                event.arrows.y = 1;
                break;
            case SDLK_DOWN:
                event.arrows.y = -1;
                break;
            case SDLK_LEFT:
                event.arrows.x = -1;
                break;
            case SDLK_RIGHT:
                event.arrows.x = 1;
                break;
            case SDLK_ESCAPE:
                event.quit = 1;
            default:
                break;
            }
        } else if (tmp.type == SDL_KEYUP) {
            switch (tmp.key.keysym.sym) {
            case SDLK_UP:
                event.arrows.y = 0;
                break;
            case SDLK_DOWN:
                event.arrows.y = 0;
                break;
            case SDLK_LEFT:
                event.arrows.x = 0;
                break;
            case SDLK_RIGHT:
                event.arrows.x = 0;
                break;
            default:
                break;
            }
        }
    }

    return event;
}
