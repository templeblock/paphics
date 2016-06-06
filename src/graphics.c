#include "graphics.h"

void graphics_error_quit() {
    IMG_Quit();
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void graphics_init(Uint32 flags) {

    if (SDL_WasInit(flags)) {
        fprintf(stderr, "\nCall to init_graphics with at least one flag already initialized\n");
        graphics_error_quit();
    } else {
    
        SDL_SetMainReady();
        
        if (SDL_Init(flags) == -1) {
            fprintf(stderr, "\nUnable to initialize SDL: %s\n", SDL_GetError());
            graphics_error_quit();
        }
        
        IMG_Init(IMG_INIT_JPG);
    }
    
}

void graphics_quit() {
    IMG_Quit();
    SDL_Quit();
}

void graphics_translate_color(Uint32 int_color, SDL_Color* color) {

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

void graphics_get_screen_size(Point* screenSize) {

    SDL_DisplayMode tmp;
    
    if (SDL_GetDesktopDisplayMode(0, &tmp) != 0) {
        fprintf(stderr, "\nSDL_GetDesktopDisplayMode failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }
    
    screenSize->x = tmp.w;
    screenSize->y = tmp.h;
    
}
