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

    const Point screen_size = get_screen_size();
    int dx;
    int dy;
    int radius;
    Surface plate;
    Window w_window;
    Surface window;
    Point window_position;
    Event input;
    Uint32 color;
    Point plate_origin;
    Point plate_size;
    Sphere sphere1;
    Sphere sphere2;
    Sphere sphere3;
    Sphere sphere4;

    input = create_event();
    w_window = create_window("Démo", window_position, screen_size, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN);

    window = get_window_surface(w_window);

    plate_size = get_screen_size();
    plate_size.x /= 2;
    plate_size.y /= 2;

    plate_origin = get_screen_size();
    plate_origin.x /= 4;
    plate_origin.y /= 4;

    plate = create_surface(plate_size, plate_origin, window);

    sphere1.center.x = plate.size.x / 2;
    sphere1.center.y = plate.size.y / 2;

    dx = 1;
    dy = 1;
    color = 0xBAB073;

    radius = 7;
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

        if (is_out_of_surface_x(plate, sphere1.center.x + dx, sphere1.radius)) {
            dx = -dx;
        }

        if (is_out_of_surface_y(plate,sphere1.center.y + dy, sphere1.radius)) {
            dy = -dy;
        }

        sphere1.center.x += dx;
        sphere1.center.y += dy;
        sphere2.center.x = plate.size.x - sphere1.center.x;
        sphere2.center.y = plate.size.y - sphere1.center.y;
        sphere3.center.x = sphere1.center.x;
        sphere3.center.y = plate.size.y - sphere1.center.y;
        sphere4.center.x = plate.size.x - sphere1.center.x;
        sphere4.center.y = sphere1.center.y;

        sphere1.color = color;
        sphere2.color = color;
        sphere3.color = color;
        sphere4.color = color;

        clear_surface(window);
        clear_surface(plate);

        draw_borders_in(window, 0xFFFFFF);

        draw_borders_out(plate, 0xFF2222);

        draw_fill_sphere(plate, &sphere1);
        draw_fill_sphere(plate, &sphere2);
        draw_fill_sphere(plate, &sphere3);
        draw_fill_sphere(plate, &sphere4);

        blit_surface(plate);

        update_window(w_window);
        SDL_Delay(4);
    }

    w_window = destroy_window(w_window);

    quit_graphics();

}
