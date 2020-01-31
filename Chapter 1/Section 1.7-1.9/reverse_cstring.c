/*************************************************************************
  > File Name: reverse_cstring.c
  > Description: Ex. 1-19 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Tue Jan 28 02:24:34 2020
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
char* reverse(char line[]);

int main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%s\n", reverse(line));
    }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;        
    }
    s[i] = '\0';
    return i;
}

char* reverse(char s[])
{
    char tmp[MAXLINE];
    int len = strlen(s);

    for (int i = 0; i < len; ++i) {
        tmp[i] = s[i];
        s[i] = i < len/2 ? s[len-i-1] : tmp[len-i-1];
    }
    return s;
}
