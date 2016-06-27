#include "line.h"

static void line_draw_noVarX(const Line* line, const Uint32 color) {

    Pixel pix;
    
    pix.color = color;
    pix.position.x = line->a.x;
    
    if (line->a.y > line->b.y) {
    
        for (pix.position.y = line->b.y; pix.position.y <= line->a.y; pix.position.y++) {
            pixel_draw(line->canvas, &pix);
        }
    } else {
    
        for (pix.position.y = line->a.y; pix.position.y <= line->b.y; pix.position.y++) {
            pixel_draw(line->canvas, &pix);
        }
    }
    
}

static void line_draw_noVarY(const Line* line, const Uint32 color) {

    Pixel pix;
    
    pix.color = color;
    pix.position.y = line->a.y;
    
    if (line->a.x > line->b.x) {
    
        for (pix.position.x = line->b.x; pix.position.x <= line->a.x; pix.position.x++) {
            pixel_draw(line->canvas, &pix);
        }
    } else {
    
        for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
            pixel_draw(line->canvas, &pix);
        }
    }
    
}

static void line_draw_sameVarXY(const Line* line, const Uint32 color) {

    short int dy;
    Pixel pix;
    
    if (line->a.y < line->b.y) {
        dy = 1;
    } else {
        dy = -1;
    }
    
    pix.color = color;
    
    if (line->a.x < line->b.x) {
    
        pix.position.y = line->a.y;
        
        for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
        
            pixel_draw(line->canvas, &pix);
            pix.position.y += dy;
        }
        
    } else {
    
        pix.position.y = line->b.y;
        
        for (pix.position.x = line->b.x; pix.position.x <= line->a.x; pix.position.x++) {
        
            pixel_draw(line->canvas, &pix);
            pix.position.y -= dy;
        }
    }
    
}

static void line_draw_naive(const Line* line, const Uint32 color) {

    Point delta;
    Pixel pix;
    
    pix.color = color;
    
    if (line->a.x < line->b.x) {
    
        delta.x = line->b.x - line->a.x;
        delta.y = line->b.y - line->a.y;
        
        for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
            pix.position.y = line->a.y + delta.y * (pix.position.x - line->a.x) / delta.x;
            pixel_draw(line->canvas, &pix);
        }
        
    } else {
    
        delta.x = line->a.x - line->b.x;
        delta.y = line->a.y - line->b.y;
        
        for (pix.position.x = line->b.x; pix.position.x <= line->a.x; pix.position.x++) {
            pix.position.y = line->b.y + delta.y * (pix.position.x - line->b.x) / delta.x;
            pixel_draw(line->canvas, &pix);
        }
        
    }
}

static void line_draw_dda(const Line* line, const Point* dist, const Point* dist_abs, const Uint32 color) {

    unsigned int lenght;
    float dx;
    float dy;
    float x;
    float y;
    Pixel pix;
    
    if (dist_abs->x > dist_abs->y) {
        lenght = (unsigned int) dist_abs->x;
    } else {
        lenght = (unsigned int) dist_abs->y;
    }
    
    dx = (float) dist->x / (float) lenght;
    dy = (float) dist->y / (float) lenght;
    
    x = (float) line->a.x + 0.5f;
    y = (float) line->a.y + 0.5f;
    
    pix.color = color;
    
    while (lenght > 0) {
    
        pix.position.x = (int) lround(x);
        pix.position.y = (int) lround(y);
        
        pixel_draw(line->canvas, &pix);
        
        x += dx;
        y += dy;
        
        lenght--;
    }
}

static void line_draw_bresenham(const Line* line, const Point* dist, const Uint32 color) {

    int dx;
    int dy;
    int error;
    Pixel pix;
    
    dx = dist->x;
    dy = dist->y;
    
    pix.color = color;
    
    if (dx > 0) {
        if (dy > 0) {
            if (dx >= dy) {
                error = dx;
                dx *= 2;
                dy *= 2;
                pix.position.y = line->a.y;
                
                for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
                    pixel_draw(line->canvas, &pix);
                    error -= dy;
                    
                    if (error < 0) {
                        pix.position.y++;
                        error += dx;
                    }
                }
            } else {
                error = dy;
                dx *= 2;
                dy *= 2;
                pix.position.x = line->a.x;
                
                for (pix.position.y = line->a.y; pix.position.y <= line->b.y; pix.position.y++) {
                    pixel_draw(line->canvas, &pix);
                    error -= dx;
                    
                    if (error < 0) {
                        pix.position.x++;
                        error += dy;
                    }
                }
            }
        } else {
            if (dx >= -dy) {
                error = dx;
                dx *= 2;
                dy *= 2;
                pix.position.y = line->a.y;
                
                for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
                    pixel_draw(line->canvas, &pix);
                    error += dy;
                    
                    if (error < 0) {
                        pix.position.y--;
                        error += dx;
                    }
                }
            } else {
                error = dy;
                dx *= 2;
                dy *= 2;
                pix.position.x = line->a.x;
                
                for (pix.position.y = line->a.y; pix.position.y >= line->b.y; pix.position.y--) {
                    pixel_draw(line->canvas, &pix);
                    error += dx;
                    
                    if (error > 0) {
                        pix.position.x++;
                        error += dy;
                    }
                }
            }
        }
    } else {
        if (dy > 0) {
            if (-dx >= dy) {
                error = dx;
                dx *= 2;
                dy *= 2;
                pix.position.y = line->a.y;
                
                for (pix.position.x = line->a.x; pix.position.x >= line->b.x; pix.position.x--) {
                    pixel_draw(line->canvas, &pix);
                    error += dy;
                    
                    if (error >= 0) {
                        pix.position.y++;
                        error += dx;
                    }
                }
            } else {
                error = dy;
                dx *= 2;
                dy *= 2;
                pix.position.x = line->a.x;
                
                for (pix.position.y = line->a.y; pix.position.y <= line->b.y; pix.position.y++) {
                    pixel_draw(line->canvas, &pix);
                    error += dx;
                    
                    if (error <= 0) {
                        pix.position.x--;
                        error += dy;
                    }
                }
            }
        } else {
            if (dx <= dy) {
                error = dx;
                dx *= 2;
                dy *= 2;
                pix.position.y = line->a.y;
                
                for (pix.position.x = line->a.x; pix.position.x >= line->b.x; pix.position.x--) {
                    pixel_draw(line->canvas, &pix);
                    error -= dy;
                    
                    if (error >= 0) {
                        pix.position.y--;
                        error += dx;
                    }
                }
            } else {
                error = dy;
                dx *= 2;
                dy *= 2;
                pix.position.x = line->a.x;
                
                for (pix.position.y = line->a.y; pix.position.y >= line->b.y; pix.position.y--) {
                    pixel_draw(line->canvas, &pix);
                    error -= dx;
                    
                    if (error >= 0) {
                        pix.position.x--;
                        error += dy;
                    }
                }
            }
        }
    }
}

static void line_draw_generic(const Line* line, const short int algoNumber, const Uint32 color) {

    Point dist;
    
    dist.x = line->b.x - line->a.x;
    dist.y = line->b.y - line->a.y;
    
    if (dist.x == 0) {
        line_draw_noVarX(line, color);
    } else if (dist.y == 0) {
        line_draw_noVarY(line, color);
    } else {
    
        Point dist_abs;
        
        dist_abs.x = abs(dist.x);
        dist_abs.y = abs(dist.y);
        
        if (dist_abs.x == dist_abs.y) {
            line_draw_sameVarXY(line, color);
        } else if (algoNumber == 1) {
            line_draw_bresenham(line, &dist, color);
        } else if (algoNumber == 2) {
            line_draw_dda(line, &dist, &dist_abs, color);
        } else {
            line_draw_naive(line, color);
        }
    }
    
}

void line_draw(const Line* line, const Uint32 color) {
    line_draw_generic(line, 1, color);
}

void line_draw_bis(const Line* line, const Uint32 color) {
    line_draw_generic(line, 2, color);
}

void line_draw_ter(const Line* line, const Uint32 color) {
    line_draw_generic(line, 3, color);
}
