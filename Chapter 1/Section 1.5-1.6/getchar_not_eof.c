/*************************************************************************
  > File Name: getchar_not_eof.c
  > Description: Ex. 1-06 for K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sun Jan 26 00:39:05 2020
 ************************************************************************/

#include<stdio.h>

int main(int argc, const char *argv[])
{
    int c;
    while (c = getchar()) {
        printf("%c not EOF: %d\n", c, c != EOF);
    }
    return 0;
}
