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
    Event event;

    position.x = 50;
    position.y = 50;
    size.x = 800;
    size.y = 600;

    event = create_event();
    window = create_window("Démo", position, size);

    //load_window_img(window, "media/demo/img/demo.png");
    update_window(window);

    Point p1;
    Point p2;
    p1.x = 790;
    p1.y = 10;
    p2.y = p1.y;
    p2.x = 10;

    while (!event.quit) {
        event = update_event(event);
        draw_line(window.surface, p1, p2, 0x357374);
        update_window(window);
        SDL_Delay(4);
    }

    window = destroy_window(window);

    quit_graphics();

}
