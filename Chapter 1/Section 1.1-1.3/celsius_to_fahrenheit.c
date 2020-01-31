/*************************************************************************
  > File Name: celsius_to_fahrenheit.c
  > Description: Ex. 1-04 for K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Jan 25 22:40:30 2020
 ************************************************************************/

#include<stdio.h>

int main(int argc, const char *argv[])
{
    float fahr, celsius;
    float lower, upper, step;
    lower = -80;    /* lower limit of temperatuire scale */
    upper = 200;    /* upper limit */
    step = 20;      /* step size */
    celsius = lower;
    printf("  C      F\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.0f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
