/*************************************************************************
  > File Name: 01_strindex_rightmost.c
  > Description: Ex. 4.1 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Jan 23 19:37:28 2021
 ************************************************************************/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int max);
int strindex_r(char source[], char searchfor[]);
int strindex(char source[], char searchfor[]);

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    char pattern[1000]; /* pattern to search for */
    printf("Input pattern: ");
    get_line(pattern, MAXLINE);
    while (get_line(line, MAXLINE) > 0)
        printf("%d\n", strindex_r(line, pattern));
    return 0;
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

/* strindex_r: return rightmost index of t in s, -1 if none */
int strindex_r(char s[], char t[])
{
    int i, j, k;
    int rightmostPos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            rightmostPos = i;
    }
    return rightmostPos;  
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;  
}

