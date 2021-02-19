/*************************************************************************
  > File Name: 13_reverse_recursive.c
  > Description: Ex. 4.13 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Feb 20 02:42:47 2021
 ************************************************************************/

#include <stdio.h>

/* reverse_rc: reverses the string s of length len recursively */
void reverse_rc(char s[], int len) {
    if (len == 1 || len == 0) {
        return;
    }
    s[0] ^= s[len-1];
    s[len-1] ^= s[0];
    s[0] ^= s[len-1];
    reverse_rc(++s, len-2);
}

/* reverse: reverses the string s recursively */
int reverse(char s[]) {
    int len;
    for (len = 0; s[len] != '\0'; ++len)
        ;
    reverse_rc(s, len);
    return len;
}

int main(int argc, char *argv[])
{
    char s[100];
    while (scanf("%s", s) != EOF) {
        reverse(s);
        printf("%s\n", s);
    }
    return 0;
}
