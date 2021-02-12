/*************************************************************************
  > File Name: getch.c
  > Description: Ex. in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Feb 12 15:21:03 2021
 ************************************************************************/

#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
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
        buf[bufp++] = c;   
}
