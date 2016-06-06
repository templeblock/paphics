#include "collision.h"

bool collision_is_out_of_canvas(Canvas* canvas, Point a, int radius) {

    bool is_out = false;
    
    if (collision_is_out_of_canvas_x(canvas, a.x, radius)) {
        is_out = true;
    }
    
    if (collision_is_out_of_canvas_y(canvas, a.y, radius)) {
        is_out = true;
    }
    
    return is_out;
}

bool collision_is_out_of_canvas_x(Canvas* canvas, int a, int radius) {

    bool is_out;
    
    is_out = false;
    
    if (a + radius > canvas->size.x) {
        is_out = true;
    } else if (a - radius < 0) {
        is_out = true;
    }
    
    return is_out;
}

bool collision_is_out_of_canvas_y(Canvas* canvas, int a, int radius) {

    bool is_out;
    
    is_out = false;
    
    if (a + radius > canvas->size.y) {
        is_out = true;
    } else if (a - radius < 0) {
        is_out = true;
    }
    
    return is_out;
}
