#include "error.h"

void error_quit() {
    paphics_stop();
    exit(EXIT_FAILURE);
}
