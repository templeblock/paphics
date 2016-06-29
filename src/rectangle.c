#include "rectangle.h"

void rectangle_draw(const Rectangle* rectangle, const Uint32 color) {

    Line l;
    Line m;
    Line n;
    Line o;
    
    l.a = rectangle->origin;
    l.b = l.a;
    l.b.x += rectangle->size.x - 1;
    
    m.a = l.b;
    m.b = m.a;
    m.b.y += rectangle->size.y - 1;
    
    n.a = m.b;
    n.b = n.a;
    n.b.x -= rectangle->size.x - 1;
    
    o.a = n.b;
    o.b = l.a;
    
    l.canvas = rectangle->canvas;
    m.canvas = l.canvas;
    n.canvas = l.canvas;
    o.canvas = l.canvas;
    
    line_draw(&l, color);
    line_draw(&m, color);
    line_draw(&n, color);
    line_draw(&o, color);
}

void rectangle_draw_fill(const Rectangle* rectangle, const Uint32 color) {

    SDL_Rect rectTmp;
    
    rectTmp.w = rectangle->size.x;
    rectTmp.h = rectangle->size.y;
    rectTmp.x = rectangle->origin.x;
    rectTmp.y = rectangle->canvas->size.y - rectangle->origin.y - rectangle->size.y;
    
    if (SDL_FillRect(rectangle->canvas->surface, &rectTmp, color) != 0) {
        fprintf(stderr, "rectangle_draw_fill() failed: %s\n", SDL_GetError());
        error_quit();
    }
    
}

bool rectangle_contains_point(const Rectangle* rect, const Point p) {

    bool isIn;
    
    if (p.x >= rect->origin.x && p.x < rect->origin.x + rect->size.x && p.y >= rect->origin.y && p.y < rect->origin.y + rect->size.y) {
        isIn = true;
    } else {
        isIn = false;
    }
    
    return isIn;
}
