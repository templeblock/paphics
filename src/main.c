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

    init_graphics(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_AUDIO);
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
    Uint32 color1;
    Uint32 color2;
    Uint32 color3;
    Uint32 color5;
    Uint32 color7;
    Uint32 color11;
    Uint32 color13;

    Point plate_origin;
    Point plate_size;
    Sphere sphere1;
    Sphere sphere2;
    Sphere sphere3;
    Sphere sphere4;

    Sphere swindow1;
    Sphere swindow2;
    Sphere swindow3;
    Sphere swindow4;


    input = create_event();
    w_window = create_window("Démo", window_position, screen_size, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);

    window = get_window_surface(w_window);

    plate_size = window.size;
    plate_size.x /= 2;
    plate_size.y /= 2;

    plate_origin = window.size;
    plate_origin.x /= 4;
    plate_origin.y /= 4;

    plate = surface_create(plate_size, plate_origin, window);

    sphere1.center.x = plate.size.x / 2;
    sphere1.center.y = plate.size.y / 2;

    dx = 0;
    dy = 0;
    color = alea_int(0x000000, 0xFFFFFF);

    radius = 2 * window.size.x / plate.size.x;
    sphere1.radius = radius;
    sphere2.radius = radius;
    sphere3.radius = radius;
    sphere4.radius = radius;

    color1 = alea_int(0x000000, 0xFFFFFF);
    color2 = alea_int(0x000000, 0xFFFFFF);
    color3 = alea_int(0x000000, 0xFFFFFF);
    color5 = alea_int(0x000000, 0xFFFFFF);
    color7 = alea_int(0x000000, 0xFFFFFF);
    color11 = alea_int(0x000000, 0xFFFFFF);
    color13 = alea_int(0x000000, 0xFFFFFF);

    color = alea_int(0x000000, 0xFFFFFF);

    int colorPrem;
    Pixel pix1;
    Pixel pix2;
    Pixel pix3;
    Pixel pix4;
    int count0;
    int count1;

    count0 = 0;
    count1 = 0;

    //int dd;
    int maxvar = 30;

    while (!input.quit) {

        input = update_event(input);

        /*  dd = alea_int(1, 7);
          if (dd == 7) {
              dd = 13;
          } else if (dd == 6) {
              dd = 11;
          } else if (dd == 5) {
              dd = 7;
          } else if (dd == 4) {
              dd = 5;
          } else if (dd == 3) {
              dd = 3;
          } else if (dd == 2) {
              dd = 2;
          } else if (dd == 1) {
              dd = 1;
          } else {
              dd = 0;
          }

          if (alea_int(0, 1) == 0) {
              dx += dd;
              count0++;
          } else {
              dx -= dd;
              count1++;;
          }

          dd = alea_int(1, 7);
          if (dd == 7) {
              dd = 13;
          } else if (dd == 6) {
              dd = 11;
          } else if (dd == 5) {
              dd = 7;
          } else if (dd == 4) {
              dd = 5;
          } else if (dd == 3) {
              dd = 3;
          } else if (dd == 2) {
              dd = 2;
          } else if (dd == 1) {
              dd = 1;
          } else {
              dd = 0;
          }

          if (alea_int(0, 1) == 0) {
              dy += dd;
              count0++;
          } else {
              dy -= dd;
              count1++;
          }*/

        dx += input.arrows.x;
        dy += input.arrows.y;

        //dx++;
        //dy++;

        if (dy > maxvar) {
            dy = 0;
        } else if(dy < -maxvar) {
            dy = 0;
        }

        if (dx > maxvar) {
            dx = 0;
        } else if(dx < -maxvar) {
            dx = 0;
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

        pix1.position = sphere1.center;
        pix2.position = sphere2.center;
        pix3.position = sphere3.center;
        pix4.position = sphere4.center;

        surface_clear(window);

        if (input.space) {
            surface_clear(plate);
        }

        surface_draw_borders_in(window, 0xFFFFFF);

        surface_draw_borders_out(plate, 0xFFFFFF);

        if (sphere1.center.x > plate.size.x / 2) {
            colorPrem = sphere1.center.x;
        } else {
            colorPrem = sphere2.center.x;
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

        pix1.color = color;
        pix2.color = color;
        pix3.color = color;
        pix4.color = color;

        pixel_draw(plate, &pix1);
        pixel_draw(plate, &pix2);
        pixel_draw(plate, &pix3);
        pixel_draw(plate, &pix4);

        //draw_quadrilateral(plate, sphere1.center, sphere2.center, sphere3.center, sphere4.center, color);
        //color = alea_int(0x000000, 0xFFFFFF);

        swindow1 = sphere1;
        swindow2 = sphere2;
        swindow3 = sphere3;
        swindow4 = sphere4;

        swindow1.center.x *= 2;
        swindow1.center.y *= 2;
        swindow1.radius *= 2;
        swindow2.center.x *= 2;
        swindow2.center.y *= 2;
        swindow2.radius *= 2;
        swindow3.center.x *= 2;
        swindow3.center.y *= 2;
        swindow3.radius *= 2;
        swindow4.center.x *= 2;
        swindow4.center.y *= 2;
        swindow4.radius *= 2;

        sphere_draw_fill(window, &swindow1);
        //sphere_draw_fill(window, &swindow2);
        //sphere_draw_fill(window, &swindow3);
        //sphere_draw_fill(window, &swindow4);

        surface_blit(plate);
        update_window(w_window);
        SDL_Delay(4);
    }

    printf("0: %d ; 1: %d\n", count0, count1);
    printf("dx: %d ; dy: %d\n", dx, dy);

    w_window = destroy_window(w_window);

    quit_graphics();

}
