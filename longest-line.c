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
    int tlen;   /* total line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char temp[MAXLINE];     /* temp input line */
    char longest[MAXLINE];  /* longest line saved here */
    
    max = 0;
    while ((tlen = len = get_line(temp, MAXLINE)) > 0) {
        copy(line, temp);
        while (len == MAXLINE - 1 && temp[len - 1] != '\n') { /* keep reading until end of line */
            len = get_line(temp, MAXLINE);
            tlen += len;
        }
        if (tlen > max) {
            max = tlen;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("\nlongest line: %s", longest);
    if (max > MAXLINE)
        printf("...");
    printf("\n");
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;   
}
