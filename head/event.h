/**
 * \file event.h
 * \brief Everything related to events, i.e. user input.
 */

#ifndef DEF_EVENT_H
#define DEF_EVENT_H

#include <SDL2/SDL.h>
#include "point.h"

/**
 * \struct Event
 * \brief A struct used to represent events, i.e. user input.
 */
#pragma pack(push, 1)
typedef struct {
    bool quit; /*!< bool containing true if user press one of the exit key or close the current Window, else contain false. */
    bool space; /*!< bool containing true if user press the space key, else contain false. */
    Point arrows; /*!< Point representing the arrow keys. */
} Event;
#pragma pack(pop)

/**
 * \fn void event_create(Event* newEvent)
 * \brief Function to create an Event.
 *
 * \param newEvent A pointer to the Event to create.
 */
void event_create(Event* newEvent);

/**
 * \fn void event_update(Event* event)
 * \brief Function to update an Event.
 *
 * \param newEvent A pointer to the Event to update.
 */
void event_update(Event* event);

#endif
