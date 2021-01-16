/*************************************************************************
  > File Name: 06_itoa_padded_blanks.c
  > Description: Ex. 3-6 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sun Jan 17 01:38:22 2021
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    *a ^= *b, *b ^= *a, *a ^= *b;
}

void reverse(char s[])
{
    int len = strlen(s);

    for (int i = 0; i < len/2; ++i) {
        swap(&s[len-i-1], &s[i]);
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int width)
{
    int i, sign;
    i = 0;
    if ((sign = n) < 0) /* record sign */
        if(-n > 0)
            n = -n; /* make n positive */
        else {
            s[i++] = -(n % 10) + '0';
            n /= -10;
        }
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    while (i < width) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main(int argc, const char *argv[])
{
    char s[1<<7];
    int n = -134;
    itoa(n, s, 5);
    printf("Convert %d to string: \n%s\n", n, s);
    return 0;
}
