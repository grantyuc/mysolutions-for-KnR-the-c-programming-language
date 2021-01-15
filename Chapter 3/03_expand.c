/*************************************************************************
  > File Name: 03_expand.c
  > Description: Ex. 3-3 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Jan 15 12:49:51 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[])
{
    int i, j;
    char lastchar, nextchar;
    for (i = j = 0; s1[i] != '\0'; ++i) {
        nextchar = s1[i+1];
        if (i > 0 && s1[i] == '-' && lastchar < nextchar && \
                (isupper(lastchar) && isupper(nextchar) || \
                 islower(lastchar) && islower(nextchar) || \
                 isdigit(lastchar) && isdigit(nextchar))) {
            for (int c = lastchar+1; c < nextchar; ++c) {
                s2[j++] = c;
            }
        } else {
            s2[j++] = s1[i];
        }
        lastchar = s1[i];
    }
    s2[j] = '\0';
}

int main(int argc, const char *argv[])
{
    char s1[1<<7] = "---a-g4-7A-Ca-c-z-F-f--4-0-";
    char s2[1<<7];
    expand(s1, s2);
    printf("Abbreviated string: %s\n", s1);
    printf("Expanded string: %s\n", s2);
    return 0;
}
