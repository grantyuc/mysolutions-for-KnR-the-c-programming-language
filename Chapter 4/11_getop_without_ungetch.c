/*************************************************************************
  > File Name: 11_getop_without_ungetch.c
  > Description: Ex. 4.11 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Feb 20 00:04:40 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'
#define getch() (buf == EOF ? getchar() : buf)

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    static int buf = EOF;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        buf = EOF;
    buf = EOF;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
    {
        while (isdigit(s[++i] = c = getch()))
            buf = EOF;
        buf = EOF;
    }
    if (c == '.') /* collect fraction part */
    {
        while (isdigit(s[++i] = c = getch()))
            buf = EOF;
        buf = EOF;
    }
    s[i] = '\0';
    if (c != EOF)
        buf = c;
    return NUMBER;
}

