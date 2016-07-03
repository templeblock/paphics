#include "color.h"

void color_translate(const Uint32 int_color, SDL_Color* color) {

    color->r = color_get_red(int_color);
    color->g = color_get_green(int_color);
    color->b = color_get_blue(int_color);
    color->a = 0;
    
}

Uint8 color_get_red(const Uint32 color) {

    Uint8 red;
    
    red = (Uint8) ((color % 256) << 16);
    
    return red;
}

Uint8 color_get_green(const Uint32 color) {

    Uint8 green;
    
    green = (Uint8) ((color % 256) << 8);
    
    return green;
}

Uint8 color_get_blue(const Uint32 color) {

    Uint8 blue;
    
    blue = color % 256;
    
    return blue;
}
