#include <stdio.h>
#include <stdlib.h>
#include "optimize.h"
#include "func1.h"
#include "sort.h"

int main(const int argc, const char **argv)
{
    FILE *fp;
    int data =0; //データの個数
    Sample *sample = (Sample *) malloc(sizeof(Sample) *50);
    if ((fp = fopen("data.csv","r")) == NULL ) {
        printf("cannot open data.csv");
    }
    while (1) {
        char buf[100];
        if (fscanf(fp,"%[^\n]%*1[\n]",buf)==-1) {
            break;
        }
        sample[data].loc = (char *) malloc(sizeof(char) * 20);
        sscanf(buf,"%s %lf, %lf",sample[data].loc,&sample[data].alt,&sample[data].temp);
        data++;
    }
    qsort(sample,data,sizeof(sample[0]),comp_alt);
    for (int i=0;i<data;i++) {
        printf("%15s ",sample[i].loc);
        printf("%.2lf, ",sample[i].alt);
        printf("%.2lf\n",sample[i].temp);
    }
    // 引数の個数が1の時だけ、alpha に第1引数を採用し、それ以外は0.01
    const double alpha = (argc == 2) ? atof(argv[1]) : 0.01;

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

