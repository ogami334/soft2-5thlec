#include "func1.h"
#include <stdlib.h>
#include <stdio.h>

int comp_alt(const void *d1,const void *d2) {
    const Sample* p1 =(Sample *) d1;
    const Sample* p2 =(Sample *) d2;
    int res =0;
    if (p1->alt > p2->alt) {
        res =-1;
    }
    else if (p1->alt < p2->alt) {
        res =1;
    }
    return res;
}