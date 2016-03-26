#ifndef DEF_EVENT_H
#define DEF_EVENT_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "point.h"

typedef struct {
    bool quit;
    Point arrows;
} Event;

Event create_event();

Event update_event(Event event);

#endif
