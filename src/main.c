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

    position.x = 50;
    position.y = 50;
    size.x = 1000;
    size.y = 800;

    input = create_event();
    window = create_window("Démo", position, size);

    p1.x = size.x / 2;
    p1.y = size.y / 2;

    int dx;
    int dy;
    int radius;

    radius = 45;
    dx = 1;
    dy = 1;

    while (!input.quit) {

        input = update_event(input);

        dx += input.arrows.x;
        dy += input.arrows.y;

        if (is_out_of_surface_x(window.surface, p1.x + dx, radius)) {
            dx = -dx;
        }

        if (is_out_of_surface_y(window.surface, p1.y + dy, radius)) {
            dy = -dy;
        }

        p1.x += dx;
        p1.y += dy;

        clear_window(window);

        draw_fill_sphere(window.surface, p1, radius, 0x2288A2);

        update_window(window);
        SDL_Delay(2);
    }

    window = destroy_window(window);

    quit_graphics();

}
