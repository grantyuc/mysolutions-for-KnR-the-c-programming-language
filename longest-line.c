/*************************************************************************
  > File Name: longest-line.c
  > Description: Ex. 1-16 in K&R (compiler option "-ansi" is needed if keep 'getline')
  > Author: Chen, Guan-Yu
  > Created Time: Mon Jan 27 15:12:38 2020
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("\nlongest line: %s\n", longest);
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
        s[i] = '\0';
    }
    else if (i == lim-1) {  /* exceed limit, end line, keep counting */
        s[i] = '\0';
        for (--i; (c=getchar())!=EOF && c!='\n'; ++i);
        if (c == '\n') {
            ++i;
        } 
    }
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;   
}
