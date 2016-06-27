#include "circle.h"

void circle_draw(const Circle* circle, const Uint32 color) {

    int i;
    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;
    
    min.x = circle->center.x - circle->radius;
    max.x = circle->center.x + circle->radius;
    min.y = circle->center.y - circle->radius;
    max.y = circle->center.y + circle->radius;
    
    pix.canvas = circle->canvas;
    
    for (i = min.x; i <= max.x; i++) {
        dx = (float) (i - circle->center.x);
        dy = (float) sqrt((float) (circle->radius * circle->radius) - dx * dx);
        pix.position.x = i;
        
        pix.position.y = (int) ((float) circle->center.y + dy);
        pixel_draw(&pix, color);
        pix.position.y = (int) ((float) circle->center.y - dy);
        pixel_draw(&pix, color);
    }
    
    for (i = min.y; i <= max.y; i++) {
        dy = (float) (i - circle->center.y);
        dx = (float) sqrt((float) (circle->radius * circle->radius) - dy * dy);
        pix.position.y = i;
        
        pix.position.x = (int) ((float) circle->center.x + dx);
        pixel_draw(&pix, color);
        pix.position.x = (int) ((float) circle->center.x - dx);
        pixel_draw(&pix, color);
    }
}

void circle_draw_fill(const Circle* circle, const Uint32 color) {

    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;
    
    pix.canvas = circle->canvas;
    
    min.x = circle->center.x - circle->radius;
    max.x = circle->center.x + circle->radius;
    min.y = circle->center.y - circle->radius;
    max.y = circle->center.y + circle->radius;
    
    for (pix.position.x = min.x; pix.position.x <= max.x; pix.position.x++) {
    
        dx = (float) (pix.position.x - circle->center.x);
        
        for (pix.position.y = min.y; pix.position.y <= max.y; pix.position.y++) {
        
            dy = (float) (pix.position.y - circle->center.y);
            
            if (dx * dx + dy * dy <= circle->radius * circle->radius) {
                pixel_draw(&pix, color);
            }
        }
    }
}
