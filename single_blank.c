/*************************************************************************
  > File Name: single_blank.c
  > Description:Ex. 1-09 for K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sun Jan 26 15:20:00 2020
 ************************************************************************/

#include<stdio.h>
#define CHAR 1
#define BLANK 0

int main(int argc, const char *argv[])
{
    int c, state;

    state = CHAR;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (state == CHAR) {
                state = BLANK;
                putchar(c);
            }
        }
        else {
            state = CHAR;
            putchar(c);
        }
    }
    return 0;
}
