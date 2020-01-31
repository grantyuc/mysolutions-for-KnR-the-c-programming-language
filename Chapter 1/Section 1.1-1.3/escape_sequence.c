/*************************************************************************
  > File Name: escape_sequence.c
  > Description: Ex. 1-02 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sat Jan 25 14:49:17 2020
 ************************************************************************/

#include<stdio.h>
int main(int argc, const char *argv[])
{
    printf("alert:\a\n");
    printf("backspace:\btext\n");
    printf("......carriage return:\rtext\n");
    printf("horizontal tab:\ttext\ttext\ttext\n");
    printf("vertical tab:\vtext\vtext\vtext\n");
    printf("backslash, question mark, quotes:\\\?\"\'\n");
    printf("octal number:\141\n");
    printf("hexadecimal number:\x41\n");
    return 0;
}
