#include "color.h"

void color_translate(const Color* color, SDL_Color* sdlColor) {

    sdlColor->r = color_get_red(color);
    sdlColor->g = color_get_green(color);
    sdlColor->b = color_get_blue(color);
    sdlColor->a = color->alpha;
    
}

Uint8 color_get_red(const Color* color) {

    Uint8 red;
    
    red = (Uint8) ((color->rgb % 256) << 16);
    
    return red;
}

Uint8 color_get_green(const Color* color) {

    Uint8 green;
    
    green = (Uint8) ((color->rgb % 256) << 8);
    
    return green;
}

Uint8 color_get_blue(const Color* color) {

    Uint8 blue;
    
    blue = color->rgb % 256;
    
    return blue;
}
