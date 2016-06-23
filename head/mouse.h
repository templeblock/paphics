#ifndef DEF_MOUSE_H
#define DEF_MOUSE_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "error.h"

void mouse_hide(void);

void mouse_show(void);

bool mouse_is_hidden(void);

bool mouse_is_shown(void);

#endif
