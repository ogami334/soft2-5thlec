#include <stdio.h>
#include <stdlib.h>
#include "func1.h"
#include "sort.h"

int main(int argc, char **argv) {
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
        //printf("%s\n",buf);
    }
    qsort(sample,data,sizeof(sample[0]),comp_alt);
    for (int i=0;i<data;i++) {
        printf("%15s ",sample[i].loc);
        printf("%.2lf, ",sample[i].alt);
        printf("%.2lf\n",sample[i].temp);
    }
}