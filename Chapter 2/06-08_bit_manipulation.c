/*************************************************************************
  > File Name: 06-08_bit_manipulation.c
  > Description: Ex. 2-6 ~ 2-8 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Jan  7 20:12:14 2021
 ************************************************************************/

#include <stdio.h>

//Get n bits from position p
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);   
}

//Returns x with the n bits that begin at position p set to the rightmost n bits of y
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    return (x & ~(~(~0 << (p-n+1)) << n)) | ((y & ~(~0 << n)) << n);
}

//Returns x with the n bits that begin at position p inverted
unsigned int invert(unsigned int x, int p, int n)
{
    return x ^ (~(~0 << (p-n+1)) << n);
}

//Returns the value of the integer x rotated to the right by n positions
unsigned int rightrot(unsigned int x, int n)
{
    return (x >> n) | (x << sizeof(unsigned int)*8-n);
}

int main(int argc, const char *argv[])
{
    unsigned int x, y;
    x = 0xaaaaaaaa;
    y = 0x55555555;
    printf("x = %x\ny = %x\n", x, y);
    printf("setbits(x, 15, 8, y) = %x\n", setbits(x, 15, 8, y));
    printf("invert(x, 7, 4) = %x\n", invert(x, 7, 4));
    printf("rightrot(x, 5) = %x\n", rightrot(x, 5));
    return 0;
}
