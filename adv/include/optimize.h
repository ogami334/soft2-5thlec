#ifndef OPTIMIZE_OPTIMIZE_H
#define OPTIMIZE_OPTIMIZE_H
#include "func.h"

int optimize(const double alpha, const int dim, double x[], const Sample *sample,const int data,
	     void (*calc_grad)(const double [], double [],const Sample*,const int),double (*calc_value) (const double [],const Sample*, const int) );

#endif
