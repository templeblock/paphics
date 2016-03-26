#include "event.h"

Event create_event() {

    Event newEvent;

    newEvent.quit = false;

    return newEvent;
}

Event update_event(Event event) {

    SDL_Event tmp;

    while (SDL_PollEvent(&tmp) != 0) {
        if (tmp.type == SDL_QUIT) {
            event.quit = true;
        }
    }

    return event;
}
