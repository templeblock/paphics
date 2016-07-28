#include "line.h"

static void line_draw_noVarX(const Line* line, const Color* color) {

    Pixel pix;
    Line lineTmp;

    pix.canvas = line->canvas;
    pix.position.x = line->a.x;

    if (line->a.y <= line->b.y) {
        lineTmp.a = line->b;
        lineTmp.b = line->a;
    } else {
        lineTmp = *(line);
    }

    for (pix.position.y = lineTmp.b.y; pix.position.y <= lineTmp.a.y; pix.position.y++) {
        pixel_draw(&pix, color);
    }
}

static void line_draw_noVarY(const Line* line, const Color* color) {

    Line lineTmp;
    Pixel pix;

    pix.canvas = line->canvas;
    pix.position.y = line->a.y;

    if (line->a.x <= line->b.x) {
        lineTmp.a = line->b;
        lineTmp.b = line->a;
    } else {
        lineTmp = *(line);
    }

    for (pix.position.x = lineTmp.b.x; pix.position.x <= lineTmp.a.x; pix.position.x++) {
        pixel_draw(&pix, color);
    }
}

static void line_draw_sameVarXY(const Line* line, const Color* color) {

    short int dy;
    Line lineTmp;
    Pixel pix;

    if (line->a.y < line->b.y) {
        dy = 1;
    } else {
        dy = -1;
    }

    pix.canvas = line->canvas;

    if (line->a.x >= line->b.x) {
        lineTmp.a = line->b;
        lineTmp.b = line->a;
    } else {
        lineTmp = *(line);
        dy = (short int) - dy;
    }

    pix.position.y = lineTmp.a.y;

    for (pix.position.x = lineTmp.a.x; pix.position.x <= lineTmp.b.x; pix.position.x++) {
        pixel_draw(&pix, color);
        pix.position.y += dy;
    }
}

static void line_draw_naive(const Line* line, const Color* color) {

    Point delta;
    Pixel pix;

    pix.canvas = line->canvas;

    Line lineTmp;

    if (line->a.x >= line->b.x) {
        lineTmp.a = line->b;
        lineTmp.b = line->a;
    } else {
        lineTmp = *(line);
    }

    delta.x = lineTmp.b.x - lineTmp.a.x;
    delta.y = lineTmp.b.y - lineTmp.a.y;

    for (pix.position.x = lineTmp.a.x; pix.position.x <= lineTmp.b.x; pix.position.x++) {
        pix.position.y = lineTmp.a.y + delta.y * (pix.position.x - lineTmp.a.x) / delta.x;
        pixel_draw(&pix, color);
    }
}

static void line_draw_dda(const Line* line, const Point* dist, const Point* dist_abs, const Color* color) {

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

    pix.canvas = line->canvas;

    while (lenght > 0) {

        pix.position.x = (int) lround(x);
        pix.position.y = (int) lround(y);

        pixel_draw(&pix, color);

        x += dx;
        y += dy;

        lenght--;
    }
}

static Point line_switch_to_octant_zero_from(const int octant, const Point p) {

    Point newP;

    switch (octant) {
        case 0:
            newP = p;
            break;

        case 1:
            newP.x = p.y;
            newP.y = p.x;
            break;

        case 2:
            newP.x = p.y;
            newP.y = -p.x;
            break;

        case 3:
            newP.x = -p.x;
            newP.y = p.y;
            break;

        case 4:
            newP.x = -p.x;
            newP.y = -p.y;
            break;

        case 5:
            newP.x = -p.y;
            newP.y = -p.x;
            break;

        case 6:
            newP.x = -p.y;
            newP.y = p.x;
            break;

        case 7:
            newP.x = p.x;
            newP.y = -p.y;
            break;

        default:
            fprintf(stderr, "\nline_switch_to_octant_zero_from error, octant = %d ; should be between 0 and 7\n", octant);
            error_quit();
    }

    return newP;
}

static Point line_switch_from_octant_zero_to(const int octant, const Point p) {

    Point newP;

    switch (octant) {
        case 0:
            newP = p;
            break;

        case 1:
            newP.x = p.y;
            newP.y = p.x;
            break;

        case 2:
            newP.x = -p.y;
            newP.y = p.x;
            break;

        case 3:
            newP.x = -p.x;
            newP.y = p.y;
            break;

        case 4:
            newP.x = -p.x;
            newP.y = -p.y;
            break;

        case 5:
            newP.x = -p.y;
            newP.y = -p.x;
            break;

        case 6:
            newP.x = p.y;
            newP.y = -p.x;
            break;

        case 7:
            newP.x = p.x;
            newP.y = -p.y;
            break;

        default:
            fprintf(stderr, "\nline_switch_from_octant_zero_to error, octant = %d ; should be between 0 and 7\n", octant);
            error_quit();
    }

    return newP;
}

static void line_draw_bresenham(const Line* line, const Point* dist, const Color* color) {

    int dx;
    int dy;
    int error;
    Pixel pix;

    dx = dist->x;
    dy = dist->y;

    pix.canvas = line->canvas;

    if (dx > 0) {
        if (dy > 0) {
            if (dx >= dy) {
                error = dx;
                dx *= 2;
                dy *= 2;
                pix.position.y = line->a.y;

                for (pix.position.x = line->a.x; pix.position.x <= line->b.x; pix.position.x++) {
                    pixel_draw(&pix, color);
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
                    pixel_draw(&pix, color);
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
                    pixel_draw(&pix, color);
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
                    pixel_draw(&pix, color);
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
                    pixel_draw(&pix, color);
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
                    pixel_draw(&pix, color);
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
                    pixel_draw(&pix, color);
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
                    pixel_draw(&pix, color);
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

static void line_draw_generic(const Line* line, const short int algoNumber, const Color* color) {

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

void line_draw(const Line* line, const Color* color) {
    line_draw_generic(line, 1, color);
}

void line_draw_bis(const Line* line, const Color* color) {
    line_draw_generic(line, 2, color);
}

void line_draw_ter(const Line* line, const Color* color) {
    line_draw_generic(line, 3, color);
}
