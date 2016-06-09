#include "calc.h"

float calc_alea_float() {

    float alea;
    
    static int init_alea = 1;
    
    if (init_alea) {
        srand((unsigned int) getpid());
    }
    
    init_alea = 0;
    
    int rnd = rand();
    
    alea = (float) ((float) rnd / (float) RAND_MAX);
    
    return alea;
}

int calc_alea_int(int min, int max) {

    int alea;
    float aleaFloat;
    
    int fact = max - min + 1;
    
    aleaFloat = calc_alea_float();
    alea = (int) ((float) min + ((float) fact * aleaFloat));
    
    return alea;
}
