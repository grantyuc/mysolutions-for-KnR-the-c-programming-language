/*************************************************************************
  > File Name: visible_tab-bspace-bslash.c
  > Description: Ex. 1-10 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sun Jan 26 15:40:32 2020
 ************************************************************************/

#include<stdio.h>

int main(int argc, const char *argv[])
{
    int c;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\b':
                putchar('\\');
                putchar('b');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            default:
                putchar(c);
        }
    }
    return 0;
}
