#ifndef DEF_MOUSE_H
#define DEF_MOUSE_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "error.h"
#include "point.h"
#include "window.h"

void mouse_hide(void);

void mouse_show(void);

void mouse_wait_click(const Window* window, Point* click);

bool mouse_is_hidden(void);

bool mouse_is_shown(void);

#endif
