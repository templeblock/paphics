#include "canvas.h"

static void canvas_get_absolute_origin_private(const Canvas* canvas, Point* absoluteOrigin) {

    if (canvas->parent != NULL) {
        absoluteOrigin->x += canvas->origin.x;
        absoluteOrigin->y += canvas->origin.y;
        canvas_get_absolute_origin_private(canvas->parent, absoluteOrigin);
    }
}

static bool canvas_collision_canvas_private(const Canvas* canvas1, const Canvas* canvas2) {

    Point bottomLeft;
    Point bottomRight;
    Point topLeft;
    Point topRight;
    
    bottomLeft = canvas_get_bottom_left_corner(canvas1);
    bottomRight = canvas_get_bottom_right_corner(canvas1);
    topLeft = canvas_get_top_left_corner(canvas1);
    topRight = canvas_get_top_right_corner(canvas1);
    
    return (canvas_contains_point(canvas2, bottomLeft) || canvas_contains_point(canvas2, topLeft) || canvas_contains_point(canvas2, topRight) || canvas_contains_point(canvas2, bottomRight));
}

bool canvas_collision_canvas(const Canvas* canvas1, const Canvas* canvas2) {

    return (canvas_collision_canvas_private(canvas1, canvas2) || canvas_collision_canvas_private(canvas2, canvas1));
}

bool canvas_contains_point(const Canvas* canvas, const Point point) {

    Point bottomLeft;
    Point topRight;
    
    bottomLeft = canvas_get_bottom_left_corner(canvas);
    topRight = canvas_get_top_right_corner(canvas);
    
    return (point.x >= bottomLeft.x && point.y >= bottomLeft.y && point.x <= topRight.x && point.y <= topRight.y);
}

bool canvas_is_out_of_parent_bottom(const Canvas* canvas) {

    return (canvas->origin.y < 0);
}

bool canvas_is_out_of_parent_left(const Canvas* canvas) {

    return (canvas->origin.x < 0);
}

bool canvas_is_out_of_parent_right(const Canvas* canvas) {

    return (canvas->origin.x + canvas->size.x - 1 >= canvas->parent->size.x);
}

bool canvas_is_out_of_parent_top(const Canvas* canvas) {

    return (canvas->origin.y + canvas->size.y - 1 >= canvas->parent->size.y);
}

bool canvas_is_out_of_parent_x(const Canvas* canvas) {

    return (canvas_is_out_of_parent_left(canvas) || canvas_is_out_of_parent_right(canvas));
}

bool canvas_is_out_of_parent_y(const Canvas* canvas) {

    return (canvas_is_out_of_parent_bottom(canvas) || canvas_is_out_of_parent_top(canvas));
}

bool canvas_will_be_out_of_parent_bottom(const Canvas* canvas, const Point* move) {

    return (canvas->origin.y + move->y < 0);
}

bool canvas_will_be_out_of_parent_left(const Canvas* canvas, const Point* move) {

    return (canvas->origin.x + move->x < 0);
}

bool canvas_will_be_out_of_parent_right(const Canvas* canvas, const Point* move) {

    return (canvas->origin.x + canvas->size.x + move->x - 1 >= canvas->parent->size.x);
}

bool canvas_will_be_out_of_parent_top(const Canvas* canvas, const Point* move) {

    return (canvas->origin.y + canvas->size.y + move->y - 1 >= canvas->parent->size.y);
}

bool canvas_will_be_out_of_parent_x(const Canvas* canvas, const Point* move) {

    return (canvas_will_be_out_of_parent_left(canvas, move) || canvas_will_be_out_of_parent_right(canvas, move));
}

bool canvas_will_be_out_of_parent_y(const Canvas* canvas, const Point* move) {

    return (canvas_will_be_out_of_parent_bottom(canvas, move) || canvas_will_be_out_of_parent_top(canvas, move));
}

Point canvas_get_bottom_left_corner(const Canvas* canvas) {
    return canvas->origin;
}

Point canvas_get_bottom_right_corner(const Canvas* canvas) {

    Point corner;
    
    corner = canvas->origin;
    
    corner.x += canvas->size.x - 1;
    
    return corner;
}

Point canvas_get_top_left_corner(const Canvas* canvas) {

    Point corner;
    
    corner = canvas->origin;
    
    corner.y += canvas->size.y - 1;
    
    return corner;
}

Point canvas_get_top_right_corner(const Canvas* canvas) {

    Point corner;
    
    corner = canvas->origin;
    
    corner.x += canvas->size.x - 1;
    corner.y += canvas->size.y - 1;
    
    return corner;
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
        
        if (canvas_is_out_of_parent_x(canvas)) {
            fprintf(stderr, "\nWarning: trying to blit canvas outside of parent on the X axis\n");
        }
        
        if (canvas_is_out_of_parent_y(canvas)) {
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

void canvas_draw_borders_in(Canvas* canvas, const Color* color) {

    Rectangle rectTmp;
    
    rectTmp.size = canvas->size;
    rectTmp.origin.x = 0;
    rectTmp.origin.y = 0;
    rectTmp.canvas = canvas;
    
    rectangle_draw(&rectTmp, color);
}

void canvas_draw_borders_out(Canvas* canvas, const Color* color) {

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

void canvas_fill(Canvas* canvas, const Color* color) {

    if (SDL_FillRect(canvas->surface, NULL, color->rgb) != 0) {
        fprintf(stderr, "canvas_fill() failed: %s\n", SDL_GetError());
        error_quit();
    }
}

void canvas_get_absolute_origin(const Canvas* canvas, Point* absoluteOrigin) {

    absoluteOrigin->x = 0;
    absoluteOrigin->y = 0;
    
    canvas_get_absolute_origin_private(canvas, absoluteOrigin);
    
}
