#include "color.h"

void color_translate(const Uint32 int_color, SDL_Color* color) {

    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    color->r = (int_color & 0x00ff0000) / 0x10000;
    color->g = (int_color & 0x0000ff00) / 0x100;
    color->b = int_color & 0x000000ff;
    #else
    color->r = (int_color & 0x000000ff);
    color->g = (Uint8) ((int_color & 0x0000ff00) / 0x100);
    color->b = (Uint8) ((int_color & 0x00ff0000) / 0x10000);
    #endif
    
    color->a = 0;
    
    // shouldn't have to do this... would be good to find why
    color->r = (Uint8) (255 - color->r);
    color->g = (Uint8) (255 - color->g);
    color->b = (Uint8) (255 - color->b);
}
