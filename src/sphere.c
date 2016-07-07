#include "sphere.h"

void sphere_draw_fill(const Sphere* sphere, const Color* color) {

    int i;
    int nb_step;
    
    int dred;
    int dgreen;
    int dblue;
    int dradius;
    
    Uint8 tmpRed;
    Uint8 tmpGreen;
    Uint8 tmpBlue;
    
    Uint8 colorRed;
    Uint8 colorGreen;
    Uint8 colorBlue;
    
    colorRed = color_get_red(color);
    colorGreen = color_get_green(color);
    colorBlue = color_get_blue(color);
    
    Circle circle;
    Color colorToDraw;
    
    colorToDraw.alpha = 0;
    
    nb_step = (int) (((float) sphere->radius) * 0.5f);
    
    dred = (255 - colorRed) / nb_step;
    dgreen = (255 - colorGreen) / nb_step;
    dblue = (255 - colorBlue) / nb_step;
    
    dradius = sphere->radius / nb_step;
    
    circle.canvas = sphere->canvas;
    
    for (i = 0; i < nb_step; i++) {
    
        tmpRed = (Uint8) (colorRed + dred * i);
        tmpGreen = (Uint8) (colorGreen + dgreen * i);
        tmpBlue = (Uint8) (colorBlue + dblue * i);
        
        circle.center.x = sphere->center.x + i;
        circle.center.y = sphere->center.y + i;
        
        circle.radius = sphere->radius - dradius * i;
        
        colorToDraw.rgb = SDL_MapRGB(circle.canvas->surface->format, tmpRed, tmpGreen, tmpBlue);
        
        circle_draw_fill(&circle, &colorToDraw);
    }
}
