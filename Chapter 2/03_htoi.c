/*************************************************************************
  > File Name: 03_htoi.c
  > Description: Ex. 2-3 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Jan  7 14:00:23 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>

// converts a string of hexadecimal digits into equivalent integer value
int htoi(char s[])
{
    int n, c;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        return htoi(s+2);
    } else {
        n = 0;
        for (int i = 0; isxdigit(s[i]); ++i) {
            if (isdigit(s[i])) {
                c = s[i] - '0';
            } else if (isupper(s[i])) {
                c = s[i] - 'A' + 10;
            } else if (islower(s[i])) {
                c = s[i] - 'a' + 10;
            }
            n = 16 * n + c; 
        }
        return n;
    }
}

int main(int argc, const char *argv[])
{
    char c;
    char s[100];
    int i;
    do {
        printf("Input hexadecimal digits: ");
        for (i = 0; i < 99 && (c = getchar()) != EOF && c != '\n'; ++i) {
            s[i] = c;
        }
        s[i] = '\0';
        printf("Equivalent integer value: %d\n", htoi(s));
    } while(c != EOF);
    return 0;
}
