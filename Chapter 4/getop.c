/*************************************************************************
  > File Name: getop.c
  > Description: Ex. in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Feb 12 15:13:33 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include "calc.h" //getch, ungetch, NUMBER == 0

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        if (c == 's' || c == 'e' || c == 'p') {
            // for sin, exp, pow
            getch();
            getch();
        }
        return c; /* not a number */
    }
    i = 0;
    if (c == '-') {
        // peek
        c = getch();
        ungetch(c);
        // if not followed by numbers
        if (c != '.' && !isdigit(c)) {
            return '-'; /* not a number */
        }
    }

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
