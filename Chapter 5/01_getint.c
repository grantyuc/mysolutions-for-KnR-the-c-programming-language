/*************************************************************************
  > File Name: 01_getint.c
  > Description: Ex. 5.1 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Wed Feb 24 15:31:18 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
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
        if (!isdigit(nc)) {
            ungetch(c == '+' ? '+' : '-');
            return 0;
        }
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(int argc, char *argv[])
{
    int n;
    if (getint(&n))
        printf("%d\n", n);
    else
        printf("Not a valid integer\n");
    printf("Next char: %c\n", getch());
    return 0;
}
