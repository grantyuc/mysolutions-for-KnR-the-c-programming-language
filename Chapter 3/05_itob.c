/*************************************************************************
  > File Name: 05_itob.c
  > Description: Ex. 3-5 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Jan 16 00:25:04 2021
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    for (int i = 0, j = strlen(s)-1; i < j; ++i, --j) {
        s[i] ^= s[j], s[j] ^= s[i], s[i] ^= s[j];
    }
}

void itob(int n, char s[], int b)
{
    int i, sign;
    i = 0;
    if ((sign = n) < 0) /* record sign */
        if(-n > 0)
            n = -n; /* make n positive */
        else {
            s[i++] = -(n%b) < 10 ? -(n % b) + '0' : -(n % b) - 10 + 'A'; /* get next digit */
            n /= -b;
        }
    do { /* generate digits in reverse order */
        s[i++] = n%b < 10 ? n % b + '0' : n % b - 10 + 'A'; /* get next digit */
    } while ((n /= b) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(int argc, const char *argv[])
{
    char s[1<<7];
    int n = 1<<31;
    int b = 16;
    itob(n, s, b);
    printf("Convert %d to string in base %d: %s\n", n, b, s);
    return 0;
}
