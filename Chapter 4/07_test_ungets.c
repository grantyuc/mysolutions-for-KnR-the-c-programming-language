/*************************************************************************
  > File Name: 07_test_ungets.c
  > Description: Ex. in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sun Feb 14 15:09:11 2021
 ************************************************************************/

#include <stdio.h>
#include "getch.c"

int main(int argc, char *argv[])
{
    ungets("abcd");
    ungets("efgh");
    for (int i = 0; i < 10; ++i) {
        printf("%c", getch());
    }
    return 0;
}
