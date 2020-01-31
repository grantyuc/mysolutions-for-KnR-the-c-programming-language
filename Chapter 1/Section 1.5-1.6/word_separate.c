/*************************************************************************
  > File Name: word_separate.c
  > Description: Ex. 1-12 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sun Jan 26 16:03:58 2020
 ************************************************************************/

#include<stdio.h>
#define IN  1
#define OUT 0

int main(int argc, const char *argv[])
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        } else {
            state = IN;
            putchar(c);
        }
    }
    return 0;
}
