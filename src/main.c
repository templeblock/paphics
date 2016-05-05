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

void psycheLine(Canvas* window, Line* line, int j) {

    line_draw(window, line);

    if (line->b.x != 0 || line->b.y != 0) {
        if ((line->b.x + line->b.y) % j == 0) {
            line->color = 0x008800 - line->color;
        }
    }
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

    Event input = event_create();;

    Point bl;
    Point br;
    Point tl;
    Point tr;

    bl.x = 0;
    bl.y = 0;
    tl.x = 0;
    tl.y = screen_size.y - 1;
    tr.x = screen_size.x - 1;
    tr.y = screen_size.y - 1;
    br.x = screen_size.x - 1;
    br.y = 0;

    Line line;

    line.a.x = screen_size.x / 2;
    line.a.y = screen_size.y / 2;

    line.color = 0x000000;
    line.b = br;

    for (int j = 1; j < 10000 && !input.quit; j++) {

        event_update(&input);

        for (line.b = br; line.b.x >= bl.x; line.b.x--) {
            psycheLine(&window, &line, j);
        }

        for (line.b = bl; line.b.y <= tl.y; line.b.y++) {
            psycheLine(&window, &line, j);
        }

        for (line.b = tl; line.b.x <= tr.x; line.b.x++) {
            psycheLine(&window, &line, j);
        }

        for (line.b = tr; line.b.y >= br.y; line.b.y--) {
            psycheLine(&window, &line, j);
        }

        // SDL_Delay(100);

        window_update(&w_window);
    }


    graphics_quit();

}
