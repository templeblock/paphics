#include "color.h"

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
