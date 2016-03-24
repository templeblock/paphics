#include "main.h"

#define SDL_MAIN_HANDLED

// screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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

    /*
      // the window we'll be rendering to
      SDL_Window* window = NULL;

      // the surface contained by the window
      SDL_Surface* window_surface = NULL;

      // initialize SDL
      if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
          printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
      } else {
          // create window
          window = SDL_CreateWindow("Graphics demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

          if (window == NULL) {
              printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
          } else {
              // get window surface
              window_surface = SDL_GetWindowSurface(window);
              // fill the surface white
              SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 0xFF, 0xFF, 0xFF));
              // update the surface
              SDL_UpdateWindowSurface(window);
              // wait two seconds
              SDL_Delay(2000);
          }
      }

      // destroy window
      SDL_DestroyWindow(window);
      */

    // quit SDL subsystems
    SDL_Quit();

}
