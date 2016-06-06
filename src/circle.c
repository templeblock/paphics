#include "circle.h"

void circle_draw(Canvas* canvas, Circle* circle) {

    int i;
    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;
    
    pix.color = circle->color;
    
    min.x = circle->center.x - circle->radius;
    max.x = circle->center.x + circle->radius;
    min.y = circle->center.y - circle->radius;
    max.y = circle->center.y + circle->radius;
    
    for (i = min.x; i <= max.x; i++) {
        dx = (float) (i - circle->center.x);
        dy = (float) sqrt((float) (circle->radius * circle->radius) - dx * dx);
        pix.position.x = i;
        
        pix.position.y = (int) ((float) circle->center.y + dy);
        pixel_draw(canvas, &pix);
        pix.position.y = (int) ((float) circle->center.y - dy);
        pixel_draw(canvas, &pix);
    }
    
    for (i = min.y; i <= max.y; i++) {
        dy = (float) (i - circle->center.y);
        dx = (float) sqrt((float) (circle->radius * circle->radius) - dy * dy);
        pix.position.y = i;
        
        pix.position.x = (int) ((float) circle->center.x + dx);
        pixel_draw(canvas, &pix);
        pix.position.x = (int) ((float) circle->center.x - dx);
        pixel_draw(canvas, &pix);
    }
}

void circle_draw_fill(Canvas* canvas, Circle* circle) {

    float dx;
    float dy;
    Point min;
    Point max;
    Pixel pix;
    
    pix.color = circle->color;
    
    min.x = circle->center.x - circle->radius;
    max.x = circle->center.x + circle->radius;
    min.y = circle->center.y - circle->radius;
    max.y = circle->center.y + circle->radius;
    
    for (pix.position.x = min.x; pix.position.x <= max.x; pix.position.x++) {
    
        dx = (float) (pix.position.x - circle->center.x);
        
        for (pix.position.y = min.y; pix.position.y <= max.y; pix.position.y++) {
        
            dy = (float) (pix.position.y - circle->center.y);
            
            if (dx * dx + dy * dy <= circle->radius * circle->radius) {
                pixel_draw(canvas, &pix);
            }
        }
    }
}
