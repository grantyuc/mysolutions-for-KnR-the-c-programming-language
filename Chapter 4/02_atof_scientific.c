/*************************************************************************
  > File Name: 02_atof_scientific.c
  > Description: Ex. 4.2 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Jan 23 21:02:59 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000 /* maximum input line length */
/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, scisign, scival;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        scisign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (scival = 0; isdigit(s[i]); i++)
            scival = 10 * scival + (s[i] - '0');
        scival *= scisign;
        for (; scival > 0; scival--)
            power /= 10;
        for (; scival < 0; scival++)
            power *= 10;
    }
    return sign * val / power;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    // if (c == '\n')
    //     s[i++] = c;
    s[i] = '\0';
    return i;
}

/* rudimentary calculator */
int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);
    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
