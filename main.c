#include <stdlib.h>
#include <math.h>

#ifndef PREC
	#define PREC 10
#endif

long double a;
double x;

int main(){

    printf("insert number like 0.0\n");
    if(!(scanf("%fl", &x)))printf("error\n");
    a=sin(x);
    printf("%fl",a);
    return 0;
}
