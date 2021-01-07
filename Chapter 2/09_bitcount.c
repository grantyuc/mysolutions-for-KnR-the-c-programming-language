/*************************************************************************
  > File Name: 09_bitcount.c
  > Description: Ex. 2-9 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Jan  7 21:25:16 2021
 ************************************************************************/

#include <stdio.h>

//bitcount: count 1 bits in x
int bitcount(unsigned int x)
{
    int b;
    for (b = 0; x != 0 ; ++b) {
        x &= x-1;
    }
    return b;
}

int main(int argc, const char *argv[])
{
    unsigned int x = 0xaa;
    printf("x = %x\n", x);
    printf("bitcount(x) = %d\n", bitcount(x));
    return 0;
}
