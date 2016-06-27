#include "canvas.h"

static void canvas_get_absolute_origin_private(const Canvas* canvas, Point* absoluteOrigin) {

    if (canvas->parent != NULL) {
        absoluteOrigin->x += canvas->origin.x;
        absoluteOrigin->y += canvas->origin.y;
        canvas_get_absolute_origin_private(canvas->parent, absoluteOrigin);
    }
}

bool canvas_collision_canvas(const Canvas* canvas1, const Canvas* canvas2) {

    bool collision;
    
    if (canvas1->origin.x >= canvas2->origin.x && canvas1->origin.x < canvas2->origin.x + canvas2->size.x) {
        if (canvas1->origin.y >= canvas2->origin.y && canvas1->origin.y < canvas2->origin.y + canvas2->size.y) {
            collision = true;
        } else if (canvas1->origin.y + canvas1->size.y >= canvas2->origin.y && canvas1->origin.y + canvas1->size.y < canvas2->origin.y && canvas1->origin.y ) {
            collision = true;
        } else {
            collision = false;
        }
    } else if (canvas1->origin.x + canvas1->size.x >= canvas2->origin.x && canvas1->origin.x + canvas1->size.x < canvas2->origin.x + canvas2->size.x) {
        if (canvas1->origin.y >= canvas2->origin.y && canvas1->origin.y < canvas2->origin.y + canvas2->size.y) {
            collision = true;
        } else if (canvas1->origin.y + canvas1->size.y >= canvas2->origin.y && canvas1->origin.y + canvas1->size.y < canvas2->origin.y && canvas1->origin.y ) {
            collision = true;
        } else {
            collision = false;
        }
    } else {
        collision = false;
    }
    
    return collision;
}

bool canvas_is_out_of_parent_bottom(const Canvas* canvas) {

    bool is_out;
    
    if (canvas->origin.y < 0) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
}

bool canvas_is_out_of_parent_left(const Canvas* canvas) {

    bool is_out;
    
    if (canvas->origin.x < 0) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
}

bool canvas_is_out_of_parent_right(const Canvas* canvas) {

    bool is_out;
    
    if (canvas->origin.x + canvas->size.x >= canvas->parent->size.x) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
}

bool canvas_is_out_of_parent_top(const Canvas* canvas) {

    bool is_out;
    
    if (canvas->origin.y < 0 || canvas->origin.y + canvas->size.y >= canvas->parent->size.y) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
}

bool canvas_is_out_of_parent_x(const Canvas* canvas) {

    bool is_out;
    
    is_out = canvas_is_out_of_parent_left(canvas) || canvas_is_out_of_parent_right(canvas);
    
    return is_out;
}

bool canvas_is_out_of_parent_y(const Canvas* canvas) {

    bool is_out;
    
    is_out = canvas_is_out_of_parent_bottom(canvas) || canvas_is_out_of_parent_top(canvas);
    
    return is_out;
}

bool canvas_will_be_out_of_parent_bottom(const Canvas* canvas, const Point* d) {

    bool is_out;
    
    if (canvas->origin.y + d->y < 0) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
    
}

bool canvas_will_be_out_of_parent_left(const Canvas* canvas, const Point* d) {

    bool is_out;
    
    if (canvas->origin.x + d->x < 0) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
    
}

bool canvas_will_be_out_of_parent_right(const Canvas* canvas, const Point* d) {

    bool is_out;
    
    if (canvas->origin.x + canvas->size.x + d->x >= canvas->parent->size.x) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
    
}

bool canvas_will_be_out_of_parent_top(const Canvas* canvas, const Point* d) {

    bool is_out;
    
    if (canvas->origin.y + canvas->size.y + d->y >= canvas->parent->size.y) {
        is_out = true;
    } else {
        is_out = false;
    }
    
    return is_out;
    
}

bool canvas_will_be_out_of_parent_x(const Canvas* canvas, const Point* d) {

    bool is_out;
    
    is_out = canvas_will_be_out_of_parent_left(canvas, d) || canvas_will_be_out_of_parent_right(canvas, d);
    
    return is_out;
}

bool canvas_will_be_out_of_parent_y(const Canvas* canvas, const Point* d) {

    bool is_out;
    
    is_out = canvas_will_be_out_of_parent_bottom(canvas, d) || canvas_will_be_out_of_parent_top(canvas, d);
    
    return is_out;
}

void canvas_blit(Canvas* canvas) {

    if (canvas->parent != NULL) {
    
        SDL_Rect dest_rect;
        
        dest_rect.w = canvas->size.x;
        dest_rect.h = canvas->size.y;
        dest_rect.x = canvas->origin.x;
        dest_rect.y = canvas->parent->size.y - canvas->origin.y - canvas->size.y;
        
        if (SDL_BlitSurface(canvas->surface, NULL, (canvas->parent)->surface, &dest_rect) < 0) {
            fprintf(stderr, "\nBlit failed: %s\n", SDL_GetError());
            error_quit();
        }
        
        if (canvas->origin.x < 0 || canvas->origin.x + canvas->size.x >= canvas->parent->size.x) {
            fprintf(stderr, "\nWarning: trying to blit canvas outside of parent on the X axis\n");
        }
        
        if (canvas->origin.y < 0 || canvas->origin.y + canvas->size.y >= canvas->parent->size.y) {
            fprintf(stderr, "\nWarning: trying to blit canvas outside of parent on the Y axis\n");
        }
    } else {
    
        fprintf(stderr, "\nWarning: trying to blit a canvas with a NULL parent\n");
    }
}

void canvas_clear(Canvas* canvas) {

    if (SDL_FillRect(canvas->surface, NULL, 0x000000) != 0) {
        fprintf(stderr, "canvas_clear() failed: %s\n", SDL_GetError());
        error_quit();
    }
}

void canvas_create(Canvas* canvas, const Point* size, const Point* origin, Canvas* parent) {

    canvas->surface = NULL;
    canvas->surface = SDL_CreateRGBSurface(0, size->x, size->y, 32, 0, 0, 0, 0);
    
    if (canvas->surface == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        error_quit();
    }
    
    canvas->size = *size;
    canvas->parent = parent;
    canvas->origin = *origin;
    
    if (canvas_is_out_of_parent_x(canvas)) {
        fprintf(stderr, "\nWarning: trying to create canvas outside of parent on the X axis\n");
    }
    
    if (canvas_is_out_of_parent_y(canvas)) {
        fprintf(stderr, "\nWarning: trying to create canvas outside of parent on the Y axis\n");
    }
}

void canvas_create_from_window(Canvas* canvas, const Window* window) {

    canvas->parent = NULL;
    canvas->surface = SDL_GetWindowSurface(window->window);
    canvas->origin.x = 0;
    canvas->origin.y = 0;
    canvas->size.x = canvas->surface->w;
    canvas->size.y = canvas->surface->h;
    
}

void canvas_draw_borders_in(Canvas* canvas, const Uint32 color) {

    Rectangle rectTmp;
    
    rectTmp.size = canvas->size;
    rectTmp.origin.x = 0;
    rectTmp.origin.y = 0;
    rectTmp.canvas = canvas;
    
    rectangle_draw(&rectTmp, color);
}

void canvas_draw_borders_out(Canvas* canvas, const Uint32 color) {

    Rectangle rectTmp;
    
    rectTmp.size = canvas->size;
    rectTmp.size.x += 2;
    rectTmp.size.y += 2;
    rectTmp.origin = canvas->origin;
    rectTmp.origin.x--;
    rectTmp.origin.y--;
    rectTmp.canvas = canvas;
    
    rectangle_draw(&rectTmp, color);
}

void canvas_fill(Canvas* canvas, const Uint32 color) {

    if (SDL_FillRect(canvas->surface, NULL, color) != 0) {
        fprintf(stderr, "canvas_fill() failed: %s\n", SDL_GetError());
        error_quit();
    }
}

void canvas_get_absolute_origin(const Canvas* canvas, Point* absoluteOrigin) {

    absoluteOrigin->x = 0;
    absoluteOrigin->y = 0;
    
    canvas_get_absolute_origin_private(canvas, absoluteOrigin);
    
}
