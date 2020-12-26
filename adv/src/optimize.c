#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "optimize.h"
#include "func.h"

double calc_norm(const int dim, double v[])
{
  double tmp = 0;
  for (int i = 0; i < dim; i++) {
    tmp += v[i] * v[i];
  }
  tmp = sqrt(tmp);
  return tmp;
}

int optimize(const double alpha, const int dim, double x[], const Sample *sample,const int data,
             void (*calc_grad)(const double [], double [],const Sample*, const int),double (*calc_value) (const double [],const Sample*, const int) )
{
  // 勾配ベクトルを記録する領域を確保
  double *g = malloc(dim * sizeof(double));
  for (int i=0;i<dim;i++) {
    printf("%lf",g[i]);
  }
  //double *g = calloc(dim,sizeof(double));

  int iter = 0;
  while (++iter < 10000) {

    // 引数で渡された関数を使って勾配ベクトルを計算
    (*calc_grad)(x, g, sample, data);

    // 勾配ベクトルのノルムを評価
    const double norm = calc_norm(dim, g);
    printf("%3d norm = %7.4f", iter, norm);
    for (int i = 0; i < dim; i++) {
      printf(", x[%d] = %7.4f", i, x[i]);
    }
    const double value = calc_value(x,sample,data);
    printf(", value : %lf",value);
    printf("\n");

    if (norm < 0.1) {
        //printf("Temperature at the top of mtfuji is %.2lf degrees Celsius\n",3.776*x[0]+x[1]);
        break;
    }

    // 最急降下法による更新
    for (int i = 0; i < dim; i++) {
      x[i] -= alpha * g[i];
    }
  }

  free(g);

  return iter;
}

