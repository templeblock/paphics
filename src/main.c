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
    size.x = 800;
    size.y = 600;

    input = create_event();
    window = create_window("Démo", position, size);

    p1.x = 50;
    p1.y = 50;

    while (!input.quit) {
        input = update_event(input);
        p1.x += 2 * input.arrows.x;
        p1.y += 2 * input.arrows.y;

        window = clear_window(window);
        draw_fill_circle(window.surface, p1, 49, 0x4875FA);
        update_window(window);
        SDL_Delay(4);
    }

    window = destroy_window(window);

    quit_graphics();

}
