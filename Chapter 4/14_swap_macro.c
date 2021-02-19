/*************************************************************************
  > File Name: 14_swap_macro.c
  > Description: Ex. 4.14 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Feb 20 03:10:45 2021
 ************************************************************************/

#include <stdio.h>
#define swap(t, x, y) { \
    t _tmp = x; \
    x = y; \
    y = _tmp; \
}

int main(int argc, char *argv[])
{
    char a = 'a', b = 'b';
    int tmp = 1, tmp2 = 2;
    swap(char, a, b);
    swap(int, tmp, tmp2);
    printf("a = %c, b = %c\n", a, b);
    printf("tmp = %d, tmp2 = %d\n", tmp, tmp2);
    return 0;
}
