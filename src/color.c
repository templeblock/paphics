#include "color.h"

Uint8 color_get_red(const Color* color) {

    return (Uint8) (color->rgb >> 16);
}

Uint8 color_get_green(const Color* color) {

    return (Uint8) ((color->rgb >> 8) % 256);
}

Uint8 color_get_blue(const Color* color) {

    Uint8 blue;
    
    blue = color->rgb % 256;
    
    return blue;
}
