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
    Uint32 color;
    int i;
    Sphere sphere1;
    Sphere sphere2;
    Sphere sphere3;
    Sphere sphere4;


    position.x = 50;
    position.y = 50;
    size.x = 800;
    size.y = 600;

    input = create_event();
    window = create_window("Démo", position, size, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN);

    sphere1.center.x = window.size.x / 2;
    sphere1.center.y = window.size.y / 2;

    int dx;
    int dy;
    int radius;

    dx = 1;
    dy = 1;
    color = 0xEAAAAA;
    i = 0;

    radius = 20;
    sphere1.radius = radius;
    sphere2.radius = radius;
    sphere3.radius = radius;
    sphere4.radius = radius;

    while (!input.quit) {

        input = update_event(input);

        dx += input.arrows.x;
        dy += input.arrows.y;

        if (dy > 7) {
            dy--;
        } else if(dy < -7) {
            dy++;
        }

        if (dx > 7) {
            dx--;
        } else if(dx < -7) {
            dx++;
        }

        if (is_out_of_surface_x(window.surface, sphere1.center.x + dx, sphere1.radius)) {
            dx = -dx;
        }

        if (is_out_of_surface_y(window.surface,sphere1.center.y + dy, sphere1.radius)) {
            dy = -dy;
        }

        sphere1.center.x += dx;
        sphere1.center.y += dy;
        sphere2.center.x = window.size.x - sphere1.center.x;
        sphere2.center.y = window.size.y - sphere1.center.y;
        sphere3.center.x = sphere1.center.x;
        sphere3.center.y = window.size.y - sphere1.center.y;
        sphere4.center.x = window.size.x - sphere1.center.x;
        sphere4.center.y = sphere1.center.y;

        if (i == 400) {
            color += 1234567890;
            i = 0;
        } else {
            i++;
        }

        sphere1.color = color;
        sphere2.color = color;
        sphere3.color = color;
        sphere4.color = color;

        // clear_window(window);

        draw_fill_sphere(window.surface, &sphere1);
        draw_fill_sphere(window.surface, &sphere2);
        draw_fill_sphere(window.surface, &sphere3);
        draw_fill_sphere(window.surface, &sphere4);

        update_window(window);
        SDL_Delay(2);
    }

    window = destroy_window(window);

    quit_graphics();

}
