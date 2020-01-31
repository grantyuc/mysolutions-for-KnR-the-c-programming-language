/*************************************************************************
  > File Name: remove_blank.c
  > Description: Ex. 1-18 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Tue Jan 28 01:39:33 2020
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);

int main()
{
    int len;            /* current line length */
    int i;
    char line[MAXLINE]; /* current input line */
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        for (i = len; i>=0; --i) {
            if (line[i] == '\0' || line[i] == '\t' || line[i] == ' ' || line[i] == '\n') {
                continue;
            } else {
                line[i+1] = '\n';
                line[i+2] = '\0';
                break;
            }
        }
        if (i >= 0) printf("%s", line);
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
