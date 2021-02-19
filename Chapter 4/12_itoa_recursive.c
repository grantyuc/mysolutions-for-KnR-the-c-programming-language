/*************************************************************************
  > File Name: 12_itoa_recursive.c
  > Description: Ex. 4.12 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Feb 20 02:11:22 2021
 ************************************************************************/

#include <stdio.h>

/* itoa: recursive itoa, return string length */
int itoa(int n, char s[]) {
    if (n < 0) {
        s[0] = '-';
        return 1 + itoa(-n, ++s);
    }
    if (n < 10) {
        s[0] = '0' + n;
        s[1] = '\0';
        return 1;
    }
    int len = itoa(n/10, s);
    s[len] = '0' + n % 10;
    s[len+1] = '\0';
    return len + 1;
}

int main(int argc, char *argv[])
{
    char s[100];
    int n;
    while (scanf("%d", &n) != EOF) {
        int len = itoa(n, s);
        printf("%s\n", s);
        printf("%d\n", len);
    }
    return 0;
}
