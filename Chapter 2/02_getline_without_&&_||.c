/*************************************************************************
  > File Name: 02_getline_without_&&_||.c
  > Description: Ex. 2-2 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Wed Jan  6 22:11:40 2021
 ************************************************************************/

#include <stdio.h>

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

/* modified get_line: read a line into s, return length */
int get_line_md(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1; ++i)
        if ( (c=getchar())!=EOF ) {
            if (c!='\n') {
                s[i] = c;
            } else {
                break;
            }
        } else {
            break;
        }
    if (c == '\n') {
        s[i] = c;
        ++i;        
    }
    s[i] = '\0';
    return i;
}

int main(int argc, const char *argv[])
{
    char s[10];
    int len;
    len = get_line(s, 10);
    printf("Input string: %s\nLength: %d\n", s, len);
    len = get_line_md(s, 10);
    printf("Input string: %s\nLength: %d\n", s, len);

    return 0;
}
