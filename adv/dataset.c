#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
    if (argc ==1) {
        printf("dataset <seed>");
    }
    int seed = atoi(argv[1]);
    srand(seed);
    FILE *fp;
    if ((fp = fopen("dataset.dat","w")) ==NULL) {
        printf("cannot open dataset.dat");
    }
    for (int i=0;i<40;i++) {
        double x =((double)rand() / ((double)RAND_MAX + 1)) * 10;
        double y =((double)rand() / ((double)RAND_MAX + 1)) * 10;
        double rand1 =((double)rand() / ((double)RAND_MAX + 1)) * 1 -0.5;//平均0
        double rand2 =((double)rand() / ((double)RAND_MAX + 1)) * 1 -0.5;//平均0
        double z = 3*(x+rand1) + 5*(y+rand2) +7;
        fprintf(fp,"%lf %lf %lf\n",x,y,z);
    }
}