#ifndef FUNC1_H
#define FUNC1_H
#include <stdio.h>
//optimizeの例と異なり、読み取った配列に対して働きかけないといけない
typedef struct
{
  double z;   // zをa,bの定数倍+定数で表したい
  double x;  // altitude (km)
  double y; // temperature (centigrade)
} Sample;

int f_dimension();

double f_value(const double x[],const Sample *sample,const int n);

void f_gradient(const double x[], double g[],const Sample *sample,const int n);

#endif