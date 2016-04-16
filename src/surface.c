#include "surface.h"

bool surface_collision_surface(Surface* surface1, Surface* surface2) {

    bool collision;

    collision = surface_collision_surface_x(surface1, surface2) || surface_collision_surface_y(surface1, surface2);

    return collision;
}

bool surface_collision_surface_x(Surface* surface1, Surface* surface2) {

    bool collision;

    if (surface1->origin.x > surface2->origin.x && surface1->origin.x < surface2->origin.x + surface2->size.x ) {
        collision = true;
    } else if (surface2->origin.x > surface1->origin.x && surface2->origin.x < surface1->origin.x + surface1->size.x ) {
        collision = true;
    } else {
        collision = false;
    }

    return collision;
}

bool surface_collision_surface_y(Surface* surface1, Surface* surface2) {

    bool collision;

    if (surface1->origin.y > surface2->origin.y && surface1->origin.y < surface2->origin.y + surface2->size.y ) {
        collision = true;
    } else if (surface2->origin.y > surface1->origin.y && surface2->origin.y < surface1->origin.y + surface1->size.y ) {
        collision = true;
    } else {
        collision = false;
    }

    return collision;
}

bool surface_is_out_of_parent_bottom(Surface* surface) {

    bool is_out;

    if (surface->origin.y < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool surface_is_out_of_parent_left(Surface* surface) {

    bool is_out;

    if (surface->origin.x < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool surface_is_out_of_parent_right(Surface* surface) {

    bool is_out;

    if (surface->origin.x + surface->size.x > surface->parent->size.x) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool surface_is_out_of_parent_top(Surface* surface) {

    bool is_out;

    if (surface->origin.y + surface->size.y > surface->parent->size.y) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool surface_is_out_of_parent_x(Surface* surface) {

    bool is_out;

    is_out = surface_is_out_of_parent_left(surface) || surface_is_out_of_parent_right(surface);

    return is_out;
}

bool surface_is_out_of_parent_y(Surface* surface) {

    bool is_out;

    is_out = surface_is_out_of_parent_bottom(surface) || surface_is_out_of_parent_top(surface);

    return is_out;
}

bool surface_will_be_out_of_parent_bottom(Surface* surface, Point* d) {

    bool is_out;

    if (surface->origin.y + d->y < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool surface_will_be_out_of_parent_left(Surface* surface, Point* d) {

    bool is_out;

    if (surface->origin.x + d->x < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool surface_will_be_out_of_parent_right(Surface* surface, Point* d) {

    bool is_out;

    if (surface->origin.x + surface->size.x + d->x > surface->parent->size.x) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool surface_will_be_out_of_parent_top(Surface* surface, Point* d) {

    bool is_out;

    if (surface->origin.y + surface->size.y + d->y > surface->parent->size.y) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool surface_will_be_out_of_parent_x(Surface* surface, Point* d) {

    bool is_out;

    is_out = surface_will_be_out_of_parent_left(surface, d) || surface_will_be_out_of_parent_right(surface, d);

    return is_out;
}

bool surface_will_be_out_of_parent_y(Surface* surface, Point* d) {

    bool is_out;

    is_out = surface_will_be_out_of_parent_bottom(surface, d) || surface_will_be_out_of_parent_top(surface, d);

    return is_out;
}

void surface_blit(Surface* surface) {

    SDL_Rect dest_rect;

    dest_rect.w = surface->size.x;
    dest_rect.h = surface->size.y;
    dest_rect.x = surface->origin.x;
    dest_rect.y = surface->origin.y;
    //dest_rect.y = surface->surface->origin.y;
    // dest_rect.y = surface->parent->size.y - surface->origin.y + 2;

    if (SDL_BlitSurface(surface->surface, NULL, (surface->parent)->surface, &dest_rect) < 0) {
        fprintf(stderr, "\nBlit failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }
}

void surface_clear(Surface* surface) {

    SDL_FillRect(surface->surface, NULL, 0x000000);
}

void surface_create(Surface* surface, Point* size, Point* origin, Surface* parent) {

    surface->surface = NULL;
    surface->surface = SDL_CreateRGBSurface(0, size->x, size->y, 32, 0, 0, 0, 0);

    if(surface->surface == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }

    surface->size = *size;
    surface->parent = parent;
    surface->origin = *origin;
    //surface->origin.y = (parent->size.y - origin->y);

}

void surface_create_from_window(Surface* surface, Window* window) {

    surface->parent = NULL;
    surface->surface = SDL_GetWindowSurface(window->window);
    surface->origin.x = 0;
    surface->origin.y = 0;
    surface->size.x = surface->surface->w;
    surface->size.y = surface->surface->h;

}

void surface_draw_borders_in(Surface* surface, Uint32 color) {

    Point a;
    Point b;

    a.x = 1;
    a.y = 1;

    b = surface->size;

    b.x--;
    b.y--;

    rectangle_draw(surface, a, b, color);
}

void surface_draw_borders_out(Surface* surface, Uint32 color) {

    //Surface tmp;
    //tmp.surface = surface->parent->surface;

    Point a;
    Point b;

    a = surface->origin;
    b = a;

    a.x--;
    a.y--;

    b.x += surface->size.x;
    b.y += surface->size.y;

    rectangle_draw(surface->parent, a, b, color);
}

void surface_load_img(Surface* surface, char* pathToImg) {

    SDL_Surface* tmp;

    tmp = NULL;

    tmp = IMG_Load(pathToImg);

    if (tmp == NULL) {
        fprintf(stderr, "\nUnable to load image %s! SDL Error: %s\n", pathToImg, SDL_GetError());
        graphics_error_quit();
    }

    SDL_BlitSurface(tmp, NULL, surface->surface, NULL );

    SDL_FreeSurface(tmp);

}
