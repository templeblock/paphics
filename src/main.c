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

    Canvas window;

    canvas_create_from_window(&window, &w_window);

    Point plate_size = window.size;
    plate_size.x /= 2;
    plate_size.y /= 2;

    Point plate_origin = plate_size;
    plate_origin.x /= 2;
    plate_origin.y /= 2;

    Canvas plate;

    canvas_create(&plate, &plate_size, &plate_origin, &window);

    Event input = input = event_create();;

    Point bl;
    Point br;
    Point tl;
    Point tr;

    bl.x = plate.size.x / 4;
    bl.y = plate.size.y / 4;
    tl.x = plate.size.x / 4;
    tl.y = plate.size.y - plate.size.y / 4;
    tr.x = plate.size.x - plate.size.x / 4;
    tr.y = tl.y;
    br.x = tr.x;
    br.y = bl.y;

    Line line;

    line.b = br;

    line.a.x = plate.size.x / 2;
    line.a.y = plate.size.y / 2;

    line.color = 0x987654;

    rectangle_draw(&plate, bl, tr, 0xFFFFFF);

    canvas_draw_borders_out(&plate, 0xFFFFFF);

    canvas_draw_borders_in(&window, 0xFFFFFF);

    Point tmp;

    while (!input.quit) {

        event_update(&input);

        if (input.space) {
            canvas_clear(&plate);
        }

        if (line.b.x > bl.x && line.b.y == br.y) {
            line.b.x--;
        } else if (line.b.y < tl.y && line.b.x == bl.x) {
            line.b.y++;
        } else if (line.b.x < tr.x && line.b.y == tl.y) {
            line.b.x++;
        } else {
            line.b.y--;
        }

        tmp = line.b;
        line.b = line.a;
        line.a = tmp;

        line_draw(&plate, &line);

        tmp = line.b;
        line.b = line.a;
        line.a = tmp;

        canvas_blit(&plate);

        window_update(&w_window);

        SDL_Delay(4);
    }

    window_destroy(&w_window);

    graphics_quit();

}
