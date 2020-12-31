/*************************************************************************
  > File Name: entab.c
  > Description: Ex. 1-21 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Wed Jan 29 14:30:34 2020
 ************************************************************************/

#include <stdio.h>
#define TABSTOP 8

int main(int argc, const char *argv[])
{
    int c, col, count;

    col = count = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                ++col;
                ++count;
                if (col % TABSTOP == 0) {
                    putchar('\t');
                    count = 0;
                }
                break;
            case '\t':
                while (col % TABSTOP != 0)
                    ++col;
                putchar('\t');
                count = 0;
                break;
            case '\n':
                col = count = 0;
                putchar(c);
                break;
            default:
                ++col;
                for (; count > 0; --count) {
                    putchar(' ');
                }
                putchar(c);
        }
    }
    return 0;
}
