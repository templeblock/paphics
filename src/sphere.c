#include "sphere.h"

void sphere_draw_fill(const Sphere* sphere, const Color* color) {

    int nb_step = (int) (((float) sphere->radius) * 0.5f);
    
    Uint8 colorRed = color_get_red(color);
    Uint8 colorGreen = color_get_green(color);
    Uint8 colorBlue = color_get_blue(color);
    
    int dred = (255 - colorRed) / nb_step;
    int dgreen = (255 - colorGreen) / nb_step;
    int dblue = (255 - colorBlue) / nb_step;
    int dradius = sphere->radius / nb_step;
    
    int i;
    Uint8 tmpRed;
    Uint8 tmpGreen;
    Uint8 tmpBlue;
    
    Color colorTmp;
    colorTmp.alpha = 0;
    
    Circle circle;
    circle.canvas = sphere->canvas;
    
    for (i = 0; i < nb_step; i++) {
    
        tmpRed = (Uint8) (colorRed + dred * i);
        tmpGreen = (Uint8) (colorGreen + dgreen * i);
        tmpBlue = (Uint8) (colorBlue + dblue * i);
        
        circle.center.x = sphere->center.x + i;
        circle.center.y = sphere->center.y + i;
        
        circle.radius = sphere->radius - dradius * i;
        
        colorTmp.rgb = SDL_MapRGB(circle.canvas->surface->format, tmpRed, tmpGreen, tmpBlue);
        
        circle_draw_fill(&circle, &colorTmp);
    }
}
