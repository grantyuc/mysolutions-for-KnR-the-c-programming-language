/*************************************************************************
  > File Name: histogram_word_length.c
  > Description: Ex. 1-13 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Mon Jan 27 02:18:04 2020
 ************************************************************************/

#include<stdio.h>
#define IN  1
#define OUT 0
#define MAX_LENGTH 20

int main(int argc, const char *argv[])
{
    int c, wlen, state, maxlen;
    int word_statics[MAX_LENGTH + 1];

    wlen = maxlen = 0;
    state = OUT;
    for (int i = 0; i < MAX_LENGTH + 1; ++i) {
        word_statics[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '-') {
            ++wlen;
            state = IN;
        }
        else if (state == IN) {
            ++word_statics[wlen];
            state = OUT;
            if (maxlen < wlen) maxlen = wlen;
            wlen = 0;
        }
    }

    if (maxlen > MAX_LENGTH) {
        printf("Error: exceed MAX_LENGTH.\n");
        return 1;
    }

    printf("\nHorizontal histogram:\n\n");
    for (int i = 1; i <= maxlen; ++i) {
        printf("%2d | ", i);
        for (int j = 0; j < word_statics[i]; ++j) {
            printf("█");
        }
        printf(" %d\n", word_statics[i]);
    }
    printf("\n");


    int maxcount = 0;
    for (int i = 1; i <= maxlen; ++i) {
        if (maxcount < word_statics[i]) maxcount = word_statics[i];
    }
    printf("\nVertical histogram:\n\n");
    for (int i = maxcount + 1; i > 0; --i) {
        for (int j = 1; j <= maxlen; ++j) {
            if (word_statics[j] >= i) {
                printf(" ██ ");
            }
            else if (word_statics[j] == i-1) {
                printf("%3d ", word_statics[j]);
            } 
            else {
                printf("    ");;
            }
        }
        printf("\n");
    }

    for (int j = 1; j <= maxlen; ++j) {
        printf(" -- ");
    }
    printf("\n");

    for (int j = 1; j <= maxlen; ++j) {
        printf(" %2d ", j);
    }
    printf("\n");

    return 0;
}
