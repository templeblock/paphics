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

    graphics_init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    atexit(SDL_Quit);

    Window w_window;
    Point window_position = {50, 50};
    Point screen_size = graphics_get_screen_size();

    window_create(&w_window, "Démo", &window_position, &screen_size, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);

    Surface window;

    surface_create_from_window(&window, &w_window);

    Point plate_size = window.size;
    plate_size.x /= 2;
    plate_size.y /= 2;

    Point plate_origin = plate_size;
    plate_origin.x /= 2;
    plate_origin.y /= 2;

    Surface plate;

    surface_create(&plate, &plate_size, &plate_origin, &window);

    Event input = input = event_create();;

    int dx = 0;
    int dy = 0;

    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;

    circle1.center.x = plate.size.x / 2;
    circle1.center.y = plate.size.y / 2;

    circle1.radius = 1;
    circle2.radius = circle1.radius;
    circle3.radius = circle1.radius;
    circle4.radius = circle1.radius;

    Sphere sphere1;

    sphere1.radius = 8 * window.size.x / plate.size.x;;

    int maxvar = (int) 8 * circle1.radius / (circle1.radius + circle1.radius);
    int dd;
    int colorPrem;

    Uint32 color;
    const Uint32 color1 = calc_alea_int(0x000000, 0xFFFFFF);
    const Uint32 color2 = calc_alea_int(0x000000, 0xFFFFFF);
    const Uint32 color3 = calc_alea_int(0x000000, 0xFFFFFF);
    const Uint32 color5 = calc_alea_int(0x000000, 0xFFFFFF);
    const Uint32 color7 = calc_alea_int(0x000000, 0xFFFFFF);
    const Uint32 color11 = calc_alea_int(0x000000, 0xFFFFFF);
    const Uint32 color13 = calc_alea_int(0x000000, 0xFFFFFF);

    while (!input.quit) {

        event_update(&input);

        dd = calc_alea_int(1, 7);

        switch (dd) {
        case 7:
            dd = 13;
            break;
        case 6:
            dd = 11;
            break;
        case 5:
            dd = 7;
            break;
        case 4:
            dd = 5;
            break;
        default:
            break; // in this case, it has the good value so...
        }

        if (calc_alea_int(0, 1) == 0) {
            dx += dd;
        } else {
            dx -= dd;
        }

        dd = calc_alea_int(1, 7);

        switch (dd) {
        case 7:
            dd = 13;
            break;
        case 6:
            dd = 11;
            break;
        case 5:
            dd = 7;
            break;
        case 4:
            dd = 5;
            break;
        default:
            break; // in this case, it has the good value so...
        }

        if (calc_alea_int(0, 1) == 0) {
            dy += dd;
        } else {
            dy -= dd;
        }

        dx += 2 * input.arrows.x;
        dy += 2 * input.arrows.y;

        //dx++;
        //dy++;

        while (dy > maxvar) {
            dy--;
        }
        while(dy < -maxvar) {
            dy++;
        }

        while (dx > maxvar) {
            dx--;
        }
        while (dx < -maxvar) {
            dx++;
        }

        if (collision_is_out_of_surface_x(&plate, circle1.center.x + dx, circle1.radius)) {
            dx = -dx;
        }

        if (collision_is_out_of_surface_y(&plate, circle1.center.y + dy, circle1.radius)) {
            dy = -dy;
        }

        circle1.center.x += dx;
        circle1.center.y += dy;
        circle2.center.x = plate.size.x - circle1.center.x;
        circle2.center.y = plate.size.y - circle1.center.y;
        circle3.center.x = circle1.center.x;
        circle3.center.y = plate.size.y - circle1.center.y;
        circle4.center.x = plate.size.x - circle1.center.x;
        circle4.center.y = circle1.center.y;

        if (circle1.center.x > plate.size.x / 2) {
            colorPrem = circle1.center.x;
        } else {
            colorPrem = circle2.center.x;
        }

        if (colorPrem % 13 == 0) {
            color = color13;
        } else if (colorPrem % 11 == 0) {
            color = color11;
        }  else if (colorPrem % 7 == 0) {
            color = color7;
        }  else if (colorPrem % 5 == 0) {
            color = color5;
        }  else if (colorPrem % 3 == 0) {
            color = color3;
        }  else if (colorPrem % 2 == 0) {
            color = color2;
        }  else {
            color = color1;
        }

        circle1.color = color;
        circle2.color = color;
        circle3.color = color;
        circle4.color = color;

        sphere1.color = color;
        sphere1.center = circle1.center;
        sphere1.center.x *= 2;
        sphere1.center.y *= 2;

        surface_clear(&window);

        if (input.space) {
            surface_clear(&plate);
        }

        surface_draw_borders_in(&window, 0xFFFFFF);
        surface_draw_borders_out(&plate, 0xFFFFFF);

        circle_draw_fill(&plate, &circle1);
        circle_draw_fill(&plate, &circle2);
        circle_draw_fill(&plate, &circle3);
        circle_draw_fill(&plate, &circle4);

        sphere_draw_fill(&window, &sphere1);

        surface_blit(&plate);
        window_update(&w_window);

        SDL_Delay(4);
    }

    SDL_Delay(4);

    window_destroy(&w_window);

    graphics_quit();

}
