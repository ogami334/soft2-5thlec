#include <stdio.h>
#include <math.h>
#include "func.h"

int f_dimension()
{
  /*
     ???
  */
 return 3;
}//必要?

double f_value(const double vec[],const Sample *sample,const int n)
{
  double res = 0;
  for (int i=0;i<n;i++) {
    res += (sample[i].z - vec[0]* sample[i].x -vec[1]*sample[i].y -vec[2]) * (sample[i].z - vec[0]* sample[i].x -vec[1]*sample[i].y -vec[2]);
  }
  /*
     ???
  */
  return res;
}

void f_gradient(const double vec[], double g[],const Sample *sample,const int n)
{
  g[0] =0;
  g[1] =0;
  g[2] =0;
  for (int i=0;i<n;i++) {
    g[0] += 2 * (sample[i].z - vec[0] * sample[i].x -vec[1]*sample[i].y -vec[2]) * (-sample[i].x);
    g[1] += 2 * (sample[i].z - vec[0] * sample[i].x -vec[1]*sample[i].y -vec[2]) * (-sample[i].y);
    g[2] += 2 * (sample[i].z - vec[0] * sample[i].x -vec[1]*sample[i].y -vec[2]) * (-1);
  }
  /*
     ???
  */
}
