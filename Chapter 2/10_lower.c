/*************************************************************************
  > File Name: 10_lower.c
  > Description: Ex. 2-10 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Jan  7 21:39:15 2021
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>

char* lower(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i) {
        s[i] = isupper(s[i]) ? s[i]-'A'+'a' : s[i];
    }
    return s;
}

int main(int argc, const char *argv[])
{
    char s[] = "ThIs IS a MOunTaIN!";
    printf("s = %s\n", s);
    printf("lower(s) = %s\n", lower(s));
    return 0;
}
