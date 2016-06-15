#include "collision.h"

bool collision_is_out_of_canvas(const Canvas* canvas, const Point a, const int radius) {

    bool is_out;
    
    if (collision_is_out_of_canvas_x(canvas, a.x, radius)) {
        is_out = true;
    } else if (collision_is_out_of_canvas_y(canvas, a.y, radius)) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
}

bool collision_is_out_of_canvas_x(const Canvas* canvas, const int a, const int radius) {

    bool is_out;
    
    if (a + radius > canvas->size.x) {
        is_out = true;
    } else if (a - radius < 0) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
}

bool collision_is_out_of_canvas_y(const Canvas* canvas, const int a, const int radius) {

    bool is_out;
    
    if (a + radius > canvas->size.y) {
        is_out = true;
    } else if (a - radius < 0) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
}
