/*************************************************************************
  > File Name: 01_binary_search.c
  > Description: Ex. 3-1 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Jan  8 14:23:41 2021
  > Reference: https://clc-wiki.net/wiki/K&R2_solutions:Chapter_3:Exercise_1
 ************************************************************************/

#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
        
    }
    return -1; /* no match */
    
}

/* binsearch_1: one-test-inside version */
int binsearch_1(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low+high)/2;
        if (x <= v[mid])
            high = mid;
        else 
            low = mid + 1;
    }
    if (x == v[mid]) {
        return mid; /* found match */
    }
    else 
        return -1; /* no match */
    
}

int latency(int x, int v[], int n)
{
    return x;
}

#define SIZE 2000000
//#define BS binsearch
//#define BS binsearch_1
#define BS latency

int main(int argc, const char *argv[])
{
    int v[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        v[i] = i;
    }
    printf("v[%d] = [0, 1, 2, ..., %d]\n", SIZE, SIZE-1);
    printf("The position of number 53 in v[] is %d.\n", BS(53, v, SIZE));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < 20; ++j) {
            BS(i, v, SIZE);
        }
    }
    return 0;
}
