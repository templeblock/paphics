#include "line.h"

void line_draw(Canvas* canvas, Line* line) {

    Point dist;

    dist.x = line->b.x - line->a.x;
    dist.y = line->b.y - line->a.y;

    if (dist.x == 0) {
        line_draw_noVarX(canvas, line);
    } else if (dist.y == 0) {
        line_draw_noVarY(canvas, line);
    } else {

        Point dist_abs;

        dist_abs.x = abs(dist.x);
        dist_abs.y = abs(dist.y);

        if (dist_abs.x == dist_abs.y) {
            line_draw_sameVarXY(canvas, line);
        } else {
            //line_draw_naive(canvas, line);
            //line_draw_dda(canvas, line, &dist, &dist_abs);
            line_draw_bresenham(canvas, line, &dist);
        }
    }
}

void line_draw_noVarX(Canvas* canvas, Line* line) {

    Pixel pix;

    pix.color = line->color;
    pix.position.x = line->a.x;

    if (line->a.y > line->b.y) {

        for (pix.position.y = line->b.y; pix.position.y <= line->a.y; pix.position.y++) {
            pixel_draw(canvas, &pix);
        }
    } else {

        for (pix.position.y = line->a.y; pix.position.y <= line->b.y; pix.position.y++) {
            pixel_draw(canvas, &pix);
        }
    }

}

void line_draw_noVarY(Canvas* canvas, Line* line) {

    Pixel pix;

    pix.color = line->color;
    pix.position.y = line->a.y;

    if (line->a.x > line->b.x) {

        for (pix.position.x = line->b.x; pix.position.x <= line->a.x; pix.position.x++) {
            pixel_draw(canvas, &pix);
        }
    } else {

        for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
            pixel_draw(canvas, &pix);
        }
    }

}

void line_draw_sameVarXY(Canvas* canvas, Line* line) {

    short int dy;
    Pixel pix;

    if (line->a.y < line->b.y) {
        dy = 1;
    } else {
        dy = -1;
    }

    pix.color = line-> color;

    if (line->a.x < line->b.x) {

        pix.position.y = line->a.y;

        for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {

            pixel_draw(canvas, &pix);
            pix.position.y += dy;
        }

    } else {

        pix.position.y = line->b.y;

        for (pix.position.x = line->b.x; pix.position.x <= line->a.x; pix.position.x++) {

            pixel_draw(canvas, &pix);
            pix.position.y -= dy;
        }
    }

}

void line_draw_naive(Canvas* canvas, Line* line) {

    Point delta;
    Pixel pix;

    pix.color = line->color;

    if (line->a.x < line->b.x) {

        delta.x = line->b.x - line->a.x;
        delta.y = line->b.y - line->a.y;

        for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
            pix.position.y = line->a.y + delta.y * (pix.position.x - line->a.x) / delta.x;
            pixel_draw(canvas, &pix);
        }

    } else {

        delta.x = line->a.x - line->b.x;
        delta.y = line->a.y - line->b.y;

        for (pix.position.x = line->b.x; pix.position.x <= line->a.x; pix.position.x++) {
            pix.position.y = line->b.y + delta.y * (pix.position.x - line->b.x) / delta.x;
            pixel_draw(canvas, &pix);
        }

    }
}

void line_draw_dda(Canvas* canvas, Line* line, Point* dist, Point* dist_abs) {

    int lenght;
    float dx;
    float dy;
    float x;
    float y;
    int i;
    Pixel pix;

    if (dist_abs->x > dist_abs->y) {
        lenght = dist_abs->x;
    } else {
        lenght = dist_abs->y;
    }

    dx = (float) dist->x / lenght;
    dy = (float) dist->y / lenght;

    x = line->a.x + 0.5;
    y = line->a.y + 0.5;

    pix.color = line->color;

    for (i = 1; i <= lenght; i++) {

        pix.position.x = (int) trunc(x);
        pix.position.y = (int) trunc(y);

        pixel_draw(canvas, &pix);

        x += dx;
        y += dy;
    }
}

void line_draw_bresenham(Canvas* canvas, Line* line, Point* dist) {

    int dx;
    int dy;
    int error;
    Pixel pix;

    dx = dist->x;
    dy = dist->y;

    pix.color = line->color;

    if (dx > 0) {
        if (dy > 0) {
            if (dx >= dy) {
                error = dx;
                dx *= 2;
                dy *= 2;
                pix.position.y = line->a.y;
                for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
                    pixel_draw(canvas, &pix);
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
                    pixel_draw(canvas, &pix);
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
                    pixel_draw(canvas, &pix);
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
                    pixel_draw(canvas, &pix);
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
                    pixel_draw(canvas, &pix);
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
                    pixel_draw(canvas, &pix);
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
                    pixel_draw(canvas, &pix);
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
                    pixel_draw(canvas, &pix);
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
