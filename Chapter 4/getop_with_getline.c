/*************************************************************************
  > File Name: getop_with_getline.c
  > Description: Ex. 4.10 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Feb 18 13:24:45 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'

/* getop: get next character or numeric operand */
int getop(char s[], char **pl)
{
    int i, c;
    while ((s[0] = c = *(*pl)++) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        if (c == 's' || c == 'e' || c == 'p') {
            // for sin, exp, pow
            *pl += 2;
        }
        return c; /* not a number */
    }
    i = 0;
    if (c == '-') {
        // peek
        c = **pl;
        // if not followed by numbers
        if (c != '.' && !isdigit(c)) {
            return '-'; /* not a number */
        }
        if (c == '.') // collect decimal point first, deal with -.1
            s[++i] = *(*pl)++;
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = *(*pl)++))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = *(*pl)++))
            ;
    s[i] = '\0';
    if (c != '\0')
        (*pl)--;
    return NUMBER;
}
