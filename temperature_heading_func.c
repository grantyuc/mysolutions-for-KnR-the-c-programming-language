/*************************************************************************
  > File Name: temperature_heading_func.c
  > Description: Ex. 1-15
  > Author: Chen, Guan-Yu
  > Created Time: Mon Jan 27 14:06:25 2020
 ************************************************************************/

#include<stdio.h>

float ftoc(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}

int main(int argc, const char *argv[])
{
    float fahr;
    float lower, upper, step;
    lower = 0;      /* lower limit of temperatuire scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */
    fahr = lower;
    printf("  C      F\n");
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
        fahr = fahr + step;   
    }
    return 0;
}

