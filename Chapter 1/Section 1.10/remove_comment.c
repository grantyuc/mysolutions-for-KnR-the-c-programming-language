/*************************************************************************
  > File Name: remove_comment.c
  > Description: Ex. 1-23 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Wed Jan 29 19:12:01 2020
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
    enum in_out_comments {OUT, LISTEN, INLINE, INBLOCK, STRING, CHAR};
    int state = OUT;
    int c, lc; // current and last character

    while ((c = getchar()) != EOF) {
        switch (state) {
            case OUT:
                if (c == '/') {
                    state = LISTEN;
                    lc = c;
                } else if (c == '"') {
                    state = STRING;
                    putchar(c);
                } else if (c == '\'') {
                    state = CHAR;
                    putchar(c);
                } else {
                    putchar(c);
                }
                break;
            case LISTEN:
                if (lc == '/') {                    /* come from OUT */
                    if (c == '/' && lc == '/') {
                        state = INLINE;
                    } else if (c == '*') {
                        state = INBLOCK;
                    } else {
                        state = OUT;
                        putchar(lc);
                        putchar(c);
                    }
                }
                else if (lc == '*' && c == '/')     /* come from INBLOCK */
                    state = OUT;
                break;
            case INLINE:
                if (c == '\n') {
                    state = OUT;
                    putchar(c);
                }
                break;
            case INBLOCK:
                if (c == '*') {
                    state = LISTEN;
                    lc = c;
                }
                break;
            case STRING:
                if (c == '"') {
                    state = OUT;
                }
                putchar(c);
                break;
            case CHAR:
                if (c == '\'') {
                    state = OUT;
                }
                putchar(c);
                break;
        }
    }
    return 0;
}
