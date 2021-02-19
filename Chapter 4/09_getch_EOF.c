/*************************************************************************
  > File Name: 09_getch_EOF.c
  > Description: Ex. 4.9 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Feb 18 13:13:08 2021
  > Reference: https://stackoverflow.com/questions/18818349/kr-c-exercise-4-9-why-ignore-eof
 ************************************************************************/

#include <stdio.h>
#define BUFSIZE 100

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c; // cast int into char in original code, cannot handle EOF == -1 properly
}
