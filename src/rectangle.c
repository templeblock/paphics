#include "rectangle.h"

void rectangle_draw(Canvas* canvas, const Rectangle* rectangle, const Uint32 color) {

    Line l;
    Line m;
    Line n;
    Line o;
    
    l.color = color;
    m.color = color;
    n.color = color;
    o.color = color;
    
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
    
    line_draw(canvas, &l);
    line_draw(canvas, &m);
    line_draw(canvas, &n);
    line_draw(canvas, &o);
}

void rectangle_draw_fill(Canvas* canvas, const Rectangle* rectangle, const Uint32 color) {

    SDL_Rect rectTmp;
    
    rectTmp.w = rectangle->size.x;
    rectTmp.h = rectangle->size.y;
    rectTmp.x = rectangle->origin.x;
    rectTmp.y = canvas->size.y - rectangle->origin.y - rectangle->size.y;
    
    if (SDL_FillRect(canvas->surface, &rectTmp, color) != 0) {
        fprintf(stderr, "rectangle_draw_fill() failed: %s\n", SDL_GetError());
        error_quit();
    }
    
}
