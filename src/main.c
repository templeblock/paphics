#include "main.h"

#define SDL_MAIN_HANDLED

int main(int argc, char** args) {

    system("clear");

    int foo = argc;
    foo++;
    char* bar = args[0];
    bar[0] = '0';

    demo();

    return EXIT_SUCCESS;
}

void demo() {

    init_graphics(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO);
    atexit(SDL_Quit);

    Window window;
    Point position;
    Point size;
    Event input;
    Point p1;
    Uint32 color;
    Point p2;
    Point p3;
    Point p4;
    int i;

    position.x = 50;
    position.y = 50;
    size.x = 800;
    size.y = 600;

    input = create_event();
    window = create_window("Démo", position, size);

    p1.x = size.x / 2;
    p1.y = size.y / 2;

    int dx;
    int dy;
    int radius;

    radius = 27;
    dx = 2;
    dy = 1;
    color = 0x000000;
    i = 0;

    while (!input.quit) {

        input = update_event(input);

        dx += input.arrows.x;
        dy += input.arrows.y;

        if (dy > 5) {
            dy--;
        } else if(dy < -5) {
            dy++;
        }

        if (dx > 5) {
            dx--;
        } else if(dx < -5) {
            dx++;
        }

        if (is_out_of_surface_x(window.surface, p1.x + dx, radius)) {
            dx = -dx;
        }

        if (is_out_of_surface_y(window.surface, p1.y + dy, radius)) {
            dy = -dy;
        }

        p1.x += dx;
        p1.y += dy;
        p2.x = size.x - p1.x;
        p2.y = size.y - p1.y;
        p3.x = p1.x;
        p3.y = size.y - p1.y;
        p4.x = size.x - p1.x;
        p4.y = p1.y;

        if (i == 400) {
            color += 1234567890;
            i = 0;
        } else {
            i++;
        }

        clear_window(window);

        draw_fill_sphere(window.surface, p1, radius, color);
        draw_fill_sphere(window.surface, p2, radius, color);
        draw_fill_sphere(window.surface, p3, radius, color);
        draw_fill_sphere(window.surface, p4, radius, color);

        update_window(window);
        SDL_Delay(4);
    }

    window = destroy_window(window);

    quit_graphics();

}
