#ifndef DEF_EVENT_H
#define DEF_EVENT_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "point.h"

#pragma pack(push, 1)
typedef struct {
    bool quit;
    bool space;
    Point arrows;
} Event;
#pragma pack(pop)

void event_create(Event* newEvent);

void event_update(Event* event);

#endif
