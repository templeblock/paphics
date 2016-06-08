#include "error.h"

void error_quit() {
    graphics_stop();
    exit(EXIT_FAILURE);
}
