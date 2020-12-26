#include <stdio.h>
#include <stdlib.h>
#include "optimize.h"
#include "func.h"

int main(const int argc, const char **argv)
{
    FILE *fp;
    int data =0; //データの個数
    Sample *sample = (Sample *) malloc(sizeof(Sample) *40);
    if (argc < 2) {
      printf("bin/adv_regression <filename> <alpha>\n");
      return 0;
    }
    if ((fp = fopen(argv[1],"r")) == NULL ) {
        printf("cannot open data.dat");
    }
    while (1) {
        char buf[100];
        if (fscanf(fp,"%[^\n]%*1[\n]",buf)==-1) {
            break;
        }
        //int scan = fscanf(fp,"%lf %lf %lf",&sample[data].x,&sample[data].y,&sample[data].z);
        sscanf(buf,"%lf %lf %lf",&sample[data].x,&sample[data].y,&sample[data].z);
        printf("%lf %lf %lf\n",sample[data].x,sample[data].y,sample[data].z);
        data++;
    }
    // 引数の個数が1の時だけ、alpha に第1引数を採用し、それ以外は0.01
    const double alpha = (argc == 3) ? atof(argv[2]) : 0.0004;

    const int dim = f_dimension();

    double *x = malloc(dim * sizeof(double));
    for (int i = 0; i < dim; i++) {
      x[i] = 0;
    }

    printf("alpha = %f\n", alpha);

    const int iter = optimize(alpha, dim, x, sample, data, f_gradient,f_value);

    printf("number of iterations = %d\n", iter);
    free(x);

    return 0;

}

