/*************************************************************************
  > File Name: 05_any.c
  > Description: Ex. 2-5 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Jan  7 17:03:49 2021
 ************************************************************************/

#include <stdio.h>

//Find the first location in s1 where any character from s2 occurs
int any(char s1[], char s2[])
{
    int i, j;
    int any;
    for (i = 0; s1[i] != '\0'; ++i) {
        any = 0;
        for (j = 0; s2[j] != '\0'; ++j)
            any |= s1[i] == s2[j];
        if (any) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char *argv[])
{
    char s1[] = "abcdefghijk";
    char s2[] = "kklldl";
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("%d\n", any(s1, s2));
    return 0;
}
