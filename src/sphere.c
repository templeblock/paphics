#include "sphere.h"

void sphere_draw_fill(const Sphere* sphere, const Color* color) {

    int i;
    int nb_step;
    
    int dred;
    int dgreen;
    int dblue;
    int dradius;
    SDL_Color colorSDL;
    SDL_Color colorTmp;
    Circle circle;
    Color colorToDraw;
    
    colorToDraw.alpha = 0;
    
    color_translate(color, &colorSDL);
    
    nb_step = (int) (((float) sphere->radius) * 0.5f);
    
    dred = (255 - colorSDL.r) / nb_step;
    dgreen = (255 - colorSDL.g) / nb_step;
    dblue = (255 - colorSDL.b) / nb_step;
    
    dradius = sphere->radius / nb_step;
    
    circle.canvas = sphere->canvas;
    
    for (i = 0; i < nb_step; i++) {
    
        colorTmp.r = (Uint8) (colorSDL.r + dred * i);
        colorTmp.g = (Uint8) (colorSDL.g + dgreen * i);
        colorTmp.b = (Uint8) (colorSDL.b + dblue * i);
        
        circle.center.x = sphere->center.x + i;
        circle.center.y = sphere->center.y + i;
        
        circle.radius = sphere->radius - dradius * i;
        
        colorToDraw.rgb = SDL_MapRGB(circle.canvas->surface->format, colorTmp.r, colorTmp.g, colorTmp.b);
        
        circle_draw_fill(&circle, &colorToDraw);
    }
}
