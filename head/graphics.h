#ifndef DEF_GRAPHICS_H
#define DEF_GRAPHICS_H

#include <stdio.h>
#include <stdarg.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "error.h"
#include "point.h"
#include "pixel.h"
#include "canvas.h"
#include "line.h"
#include "window.h"
#include "collision.h"
#include "screen.h"
#include "color.h"
#include "circle.h"
#include "sound.h"
#include "calc.h"
#include "rectangle.h"
#include "quadrilateral.h"
#include "event.h"
#include "sphere.h"
#include "image.h"

void graphics_init(Uint32 flags);

void graphics_quit(void);

#endif
