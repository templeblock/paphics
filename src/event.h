#ifndef DEF_EVENT_H
#define DEF_EVENT_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "point.h"

typedef struct {
    bool quit;
    Point arrows;
    bool space;
} Event;

Event event_create();

Event event_update(Event event);

#endif
