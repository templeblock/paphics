#include "calc.h"

float calc_alea_float() {

    float alea;

    static int init_alea = 1;

    if (init_alea) {
        srand(getpid());
    }

    init_alea = 0;

    alea = (float) rand() / (float) RAND_MAX;

    return alea;
}

int calc_alea_int(int min, int max) {

    int alea;

    alea = (int) (min + (max - min + 1) * (calc_alea_float()));

    return alea;
}
