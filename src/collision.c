#include "collision.h"

bool is_out_of_surface_x(Surface surface, int a, int radius) {

    bool is_out;

    is_out = false;

    if (a + radius > surface.size.x) {
        is_out = true;
    } else if (a - radius < 0) {
        is_out = true;
    }

    return is_out;
}

bool is_out_of_surface_y(Surface surface, int a, int radius) {

    bool is_out;

    is_out = false;

    if (a + radius > surface.size.y) {
        is_out = true;
    } else if (a - radius < 0) {
        is_out = true;
    }

    return is_out;
}
