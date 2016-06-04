#include "canvas.h"

bool canvas_collision_canvas(Canvas* canvas1, Canvas* canvas2) {

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

bool canvas_is_out_of_parent_bottom(Canvas* canvas) {

    bool is_out;

    if (canvas->origin.y < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool canvas_is_out_of_parent_left(Canvas* canvas) {

    bool is_out;

    if (canvas->origin.x < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool canvas_is_out_of_parent_right(Canvas* canvas) {

    bool is_out;

    if (canvas->origin.x + canvas->size.x >= canvas->parent->size.x) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool canvas_is_out_of_parent_top(Canvas* canvas) {

    bool is_out;

    if (canvas->origin.y < 0 || canvas->origin.y + canvas->size.y >= canvas->parent->size.y) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;
}

bool canvas_is_out_of_parent_x(Canvas* canvas) {

    bool is_out;

    is_out = canvas_is_out_of_parent_left(canvas) || canvas_is_out_of_parent_right(canvas);

    return is_out;
}

bool canvas_is_out_of_parent_y(Canvas* canvas) {

    bool is_out;

    is_out = canvas_is_out_of_parent_bottom(canvas) || canvas_is_out_of_parent_top(canvas);

    return is_out;
}

bool canvas_will_be_out_of_parent_bottom(Canvas* canvas, Point* d) {

    bool is_out;

    if (canvas->origin.y + d->y < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool canvas_will_be_out_of_parent_left(Canvas* canvas, Point* d) {

    bool is_out;

    if (canvas->origin.x + d->x < 0) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool canvas_will_be_out_of_parent_right(Canvas* canvas, Point* d) {

    bool is_out;

    if (canvas->origin.x + canvas->size.x + d->x >= canvas->parent->size.x) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool canvas_will_be_out_of_parent_top(Canvas* canvas, Point* d) {

    bool is_out;

    if (canvas->origin.y + canvas->size.y + d->y >= canvas->parent->size.y) {
        is_out = true;
    } else {
        is_out = false;
    }

    return is_out;

}

bool canvas_will_be_out_of_parent_x(Canvas* canvas, Point* d) {

    bool is_out;

    is_out = canvas_will_be_out_of_parent_left(canvas, d) || canvas_will_be_out_of_parent_right(canvas, d);

    return is_out;
}

bool canvas_will_be_out_of_parent_y(Canvas* canvas, Point* d) {

    bool is_out;

    is_out = canvas_will_be_out_of_parent_bottom(canvas, d) || canvas_will_be_out_of_parent_top(canvas, d);

    return is_out;
}

void canvas_blit(Canvas* canvas) {

    SDL_Rect dest_rect;

    dest_rect.w = canvas->size.x;
    dest_rect.h = canvas->size.y;
    dest_rect.x = canvas->origin.x;
    dest_rect.y = canvas->parent->size.y - canvas->origin.y - canvas->size.y;

    if (SDL_BlitSurface(canvas->surface, NULL, (canvas->parent)->surface, &dest_rect) < 0) {
        fprintf(stderr, "\nBlit failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }

    if (canvas->origin.x < 0 || canvas->origin.x + canvas->size.x >= canvas->parent->size.x) {
        fprintf(stderr, "\nWarning: trying to blit canvas outside of parent on the X axis\n");
    }

    if (canvas->origin.y < 0 || canvas->origin.y + canvas->size.y >= canvas->parent->size.y) {
        fprintf(stderr, "\nWarning: trying to blit canvas outside of parent on the Y axis\n");
    }
}

void canvas_clear(Canvas* canvas) {

    SDL_FillRect(canvas->surface, NULL, 0x000000);
}

void canvas_create(Canvas* canvas, Point* size, Point* origin, Canvas* parent) {

    canvas->surface = NULL;
    canvas->surface = SDL_CreateRGBSurface(0, size->x, size->y, 32, 0, 0, 0, 0);

    if (canvas->surface == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        graphics_error_quit();
    }

    canvas->size = *size;
    canvas->parent = parent;
    canvas->origin = *origin;

    if (canvas->origin.x < 0 || canvas->origin.x + canvas->size.x >= canvas->parent->size.x) {
        fprintf(stderr, "\nWarning: trying to create canvas outside of parent on the X axis\n");
    }

    if (canvas->origin.y < 0 || canvas->origin.y + canvas->size.y >= canvas->parent->size.y) {
        fprintf(stderr, "\nWarning: trying to create canvas outside of parent on the Y axis\n");
    }
}

void canvas_create_from_window(Canvas* canvas, Window* window) {

    canvas->parent = NULL;
    canvas->surface = SDL_GetWindowSurface(window->window);
    canvas->origin.x = 0;
    canvas->origin.y = 0;
    canvas->size.x = canvas->surface->w;
    canvas->size.y = canvas->surface->h;

}

void canvas_draw_borders_in(Canvas* canvas, Uint32 color) {

    Point a;
    Point b;

    a.x = 1;
    a.y = 1;

    b = canvas->size;

    b.x--;
    b.y--;

    rectangle_draw(canvas, a, b, color);
}

void canvas_draw_borders_out(Canvas* canvas, Uint32 color) {

    //Canvas tmp;
    //tmp.canvas = canvas->parent->surface;

    Point a;
    Point b;

    a = canvas->origin;
    b = a;

    a.x--;
    a.y--;

    b.x += canvas->size.x;
    b.y += canvas->size.y;

    rectangle_draw(canvas->parent, a, b, color);
}

void canvas_load_img_naive(Canvas* canvas, char* pathToImg) {

    SDL_Surface* tmp;

    tmp = NULL;

    tmp = IMG_Load(pathToImg);

    if (tmp == NULL) {
        fprintf(stderr, "\nUnable to load image %s! SDL Error: %s\n", pathToImg, SDL_GetError());
        graphics_error_quit();
    }

    SDL_BlitSurface(tmp, NULL, canvas->surface, NULL );

    SDL_FreeSurface(tmp);

}

void canvas_load_img_scaled(Canvas* canvas, char* pathToImg) {

    SDL_Surface* tmp;

    tmp = NULL;

    tmp = IMG_Load(pathToImg);

    if (tmp == NULL) {
        fprintf(stderr, "\nUnable to load image %s! SDL Error: %s\n", pathToImg, SDL_GetError());
        graphics_error_quit();
    }

    SDL_BlitScaled(tmp, NULL, canvas->surface, NULL );

    SDL_FreeSurface(tmp);

}
