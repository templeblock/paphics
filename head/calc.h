#ifndef DEF_CALC_H
#define DEF_CALC_H

#include <stdlib.h>
#include <unistd.h>

/**
 * \fn float calc_alea_float(void)
 * \brief Function to get a random float x in [0 ; 1[.
 * \return The random float.
 */
float calc_alea_float(void);

/**
 * \fn int calc_alea_int(const int min, const int max)
 * \brief Function to get a random int.
 * \param min The minimun value for the random int.
 * \param max The maximum value for the random int.
 * \return The random int.
 */
int calc_alea_int(const int min, const int max);

#endif
