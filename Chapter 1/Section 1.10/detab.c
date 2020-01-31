/*************************************************************************
  > File Name: detab.c
  > Description:Ex. 1-20 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Wed Jan 29 14:10:40 2020
 ************************************************************************/

#include <stdio.h>
#define TABSTOP 8

int main(int argc, const char *argv[])
{
    int c, col;

    col = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\n':
                putchar(c);
                col = 0;
                break;
            case '\t':
                putchar(' ');
                ++col;
                while (col % TABSTOP != 0) {
                    putchar(' ');
                    ++col;
                }
                break;
            default:
                putchar(c);
                ++col;
        }
    }
    return 0;
}
