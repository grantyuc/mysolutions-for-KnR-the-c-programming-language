/*************************************************************************
  > File Name: print_longer_lines.c
  > Description: Ex. 1-17 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Tue Jan 28 01:01:58 2020
 ************************************************************************/

#include <stdio.h>

#define MINLEN 80

int get_line(char line[], int maxline);

int main(int argc, const char *argv[])
{
    int len;
    char c;
    char line[MINLEN + 1];
    while ((len = get_line(line, MINLEN + 1)) > 0) {
        if (len == MINLEN) {
            printf("%s", line);
            if (line[len - 1] != '\n') {
                while ((c = getchar()) != EOF && c != '\n') {
                    putchar(c);
                }
                if (c == '\n') putchar(c);
            }
        } 
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
