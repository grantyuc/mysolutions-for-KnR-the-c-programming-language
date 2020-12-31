/*************************************************************************
  > File Name: fold_line.c
  > Description: Ex. 1-22 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Wed Jan 29 21:14:24 2020
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 60 /* maximum line length */
#define TABSTOP 8

int get_line(char line[], int maxline);

int main(int argc, const char *argv[])
{
    int i, lastblank, len, col;
    char line[MAXLINE + 5];
    char tmp;
    enum states {CONTI, HOLDON};
    int state = HOLDON;
    col = 0;
    while ((len = get_line(line, MAXLINE - col + 5))) {
        state = HOLDON;
        while (state) {
            i = lastblank = 0;
            /* count spacing */
            do {
                if (line[i] == '\t') {
                    while (++col % TABSTOP);
                    lastblank = i;
                } else if (line[i] == ' ') {
                    ++col;
                    lastblank = i;
                } else if (line[i] == '\n') {
                    continue;
                } else {
                    ++col;
                }
            } while (col < MAXLINE && ++i < len);
            /* i == len, or line[i] is out-spacing */

            if (i == len) {                 /* line fits in, print directly */
                printf("%s", line);
                if (line[len-1] == '\n')
                    col = 0;
                state = CONTI;
            } else if (lastblank > 0) {     /* there are blanks, print till last blank, renew line and len */
                line[lastblank] = '\0';
                printf("%s", line);
                putchar('\n');
                col = 0;
                while ((isblank(line[lastblank]) || line[lastblank] == '\n' || line[lastblank] == '\0') && lastblank < len) {
                    ++lastblank;
                }
                /* lastblank == new beginning of line */
                if ((len -= lastblank) > 0)
                    memcpy(line, line + lastblank, len + 1);
                else state = CONTI;
            } else if (line[i] == '\n' ) {   /* the out-spacing character is '\n' */
                line[i] = '\0';
                printf("%s", line);
                putchar('\n');
                col = 0;
                if ((len -= i + 1) > 0)
                    memcpy(line, line + i + 1, len + 1);
                else state = CONTI;
            } else if (line[i] == '\0' ) {   /* the out-spacing character is '\0' */
                printf("%s", line);
                state = CONTI;
            } else {
                tmp = line[i+1];
                if (!isupper(tmp) && !islower(tmp)) {   /* the lonely tail */
                    line[i+1] = '\0';
                    printf("%s", line);
                    putchar(tmp);
                    if (tmp != '\n') putchar('\n');
                    col = 0;
                    if ((len -= i + 2) > 0)
                        memcpy(line, line + i + 2, len + 1);
                    else state = CONTI;
                }
                else {
                    tmp = line[i];
                    line[i] = '\0';
                    printf("%s", line);
                    putchar('-');
                    putchar('\n');
                    col = 0;
                    len -= i + 1;
                    memcpy(line + 1, line + i + 1, len + 1);
                    line[0] = tmp;
                    ++len;
                }
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
