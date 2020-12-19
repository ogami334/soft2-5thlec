#include <stdio.h>
#include <math.h>
#include "func1.h"

/*typedef struct
{
  char *loc;   // location name
  double alt;  // altitude (km)
  double temp; // temperature (centigrade)
} Sample;*/

int f_dimension()
{
  /*
     ???
  */
 return 2;
}//必要?

double f_value(const double x[],const Sample *sample,const int n)
{
  double res = 0;
  for (int i=0;i<n;i++) {
    res += (sample[i].temp - x[0]* sample[i].alt -x[1]) * (sample[i].temp - x[0]* sample[i].alt -x[1]);
  }
  /*
     ???
  */
  return res;
}

void f_gradient(const double x[], double g[],const Sample *sample,const int n)
{
  g[0] =0;
  g[1] =0;
  for (int i=0;i<n;i++) {
    g[0] += 2 * (sample[i].temp - x[0] * sample[i].alt -x[1]) * (-sample[i].alt);
    g[1] += 2 * (sample[i].temp - x[0] * sample[i].alt -x[1]) * (-1);
  }
  /*
     ???
  */
}


/*int f_dimension()
{
  return 2;
}

double f_value(const double x[])
{
  return (x[0] - 3) * (x[0] - 3)  * (x[0] - 3)  * (x[0] - 3) + (x[1] - 2) * (x[1] - 2);
}

void f_gradient(const double x[], double g[])
{
  g[0] = 4 * (x[0] - 3) * (x[0] - 3) * (x[0] - 3);
  g[1] = 2 * (x[1] - 2);
}*/