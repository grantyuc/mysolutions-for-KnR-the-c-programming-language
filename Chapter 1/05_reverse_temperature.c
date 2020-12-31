/*************************************************************************
  > File Name: reverse_temperature.c
  > Description: Ex. 1-05 for K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Jan 25 23:15:05 2020
 ************************************************************************/

#include<stdio.h>

int main(int argc, const char *argv[])
{
    float celsius;
    int fahr;
    int lower, upper, step;
    lower = 0;      /* lower limit of temperatuire scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("  F      C\n");
    for (fahr = upper; fahr >= lower; fahr -= step) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3d %6.1f\n", fahr, celsius);
    }
    return 0;
}
