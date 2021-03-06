/**
 * \file event.h
 * \brief Everything related to events, i.e. user input.
 */

#ifndef DEF_EVENT_H
#define DEF_EVENT_H

#include <SDL2/SDL.h>
#include "point.h"

#ifdef __cplusplus
extern "C" {
#endif

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
 * \fn char event_wait_key(void)
 * \brief Function to wait for a key to be pressed and getting it's ASCII value.
 *
 * \return A char containing the ASCII value of the pressed key.
 */
char event_wait_key(void);

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
 * \param event A pointer to the Event to update.
 */
void event_update(Event* event);

#ifdef __cplusplus
}
#endif

#endif
