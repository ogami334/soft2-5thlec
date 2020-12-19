#ifndef FUNC1_H
#define FUNC1_H
#include <stdio.h>
//optimizeの例と異なり、読み取った配列に対して働きかけないといけない
typedef struct
{
  char *loc;   // location name
  double alt;  // altitude (km)
  double temp; // temperature (centigrade)
} Sample;

int f_dimension();

double f_value(const double x[],const Sample *sample,const int n);

void f_gradient(const double x[], double g[],const Sample *sample,const int n);

#endif