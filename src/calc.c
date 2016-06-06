#include "calc.h"

float calc_alea_float() {

    float alea;
    
    static int init_alea = 1;
    
    if (init_alea) {
        srand((unsigned int) getpid());
    }
    
    init_alea = 0;
    
    alea = (float) (rand() / RAND_MAX);
    
    return alea;
}

int calc_alea_int(int min, int max) {

    int alea;
    float aleaFloat;
    
    aleaFloat = calc_alea_float();
    alea = (int) (min + (max - min + 1) * ((int) aleaFloat));
    
    return alea;
}
