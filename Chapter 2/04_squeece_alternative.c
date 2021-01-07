/*************************************************************************
  > File Name: 04_squeece_alternative.c
  > Description: Ex. 2-4 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Jan  7 15:57:44 2021
 ************************************************************************/

#include <stdio.h>

/* squeeze: delete all characters in r from s */
void squeeze(char s[], char r[])
{
    int i, j, k;
    int accepted;
    for (i = j = 0; s[i] != '\0'; ++i) {
        accepted = 1;
        for (k = 0; r[k] != '\0'; ++k)
            accepted &= s[i] != r[k];
        if (accepted) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main(int argc, const char *argv[])
{
    char s1[] = "abcdefghijk123abcdacaab1113";
    char s2[] = "a1j2222ad";
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    squeeze(s1, s2);
    printf("Delete all characters in s2 from s1: \n%s\n", s1);
    return 0;
}
