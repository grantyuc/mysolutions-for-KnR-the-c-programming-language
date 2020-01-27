/*************************************************************************
  > File Name: histogram_char_frequency.c
  > Description: Ex. 1-14 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Mon Jan 27 04:01:58 2020
 ************************************************************************/

#include<stdio.h>

int main(int argc, const char *argv[])
{
    int c;
    int char_statics[128] = {0};

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < 128) {
            ++char_statics[c];
        }
    }

    printf("\nHorizontal histogram:\n\n");
    for (int i = 0; i < 128; ++i) {
        if (char_statics[i] != 0) {
            if (i == '\t') 
                printf("\\t| ");
            else if (i == '\n') 
                printf("\\n| ");
            else printf("%c | ", i);
            for (int j = 0; j < char_statics[i]; ++j) {
                printf("█");
            }
            printf(" %d\n", char_statics[i]);
        }
    }
    printf("\n");

    return 0;
}

