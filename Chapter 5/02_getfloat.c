/*************************************************************************
  > File Name: 02_getfloat.c
  > Description: Ex. 5.2 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Wed Feb 24 16:42:32 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int getch(void);
void ungetch(int);
#define MAXLEN 100

/* getfloat: get next float number from input into *pn */
int getfloat(double *pn)
{
    int c, sign;
    char s[MAXLEN];
    char *ps = s;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    if (c == '+' || c == '-') {
        /* peek */
        char nc = getch();
        ungetch(nc);
        if (!isdigit(nc) && nc != '.') {
            ungetch(c == '+' ? '+' : '-');
            return 0;
        }
    }
    if (c == '+' || c == '-') {
        *ps++ = c;
        c = getch();
    }
    for (; isdigit(c); c = getch())
        *ps++ = c;
    if (c == '.') {
        *ps++ = c;
        c = getch();
    }
    for (; isdigit(c); c = getch())
        *ps++ = c;
    *ps = '\0';
    *pn = atof(s);
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(int argc, char *argv[])
{
    double n;
    if (getfloat(&n))
        printf("%g\n", n);
    else
        printf("Not a valid float number\n");
    printf("Next char: %c\n", getch());
    return 0;
}
