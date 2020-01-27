/*************************************************************************
  > File Name: blank-tab-newline_counter.c
  > Description: Ex. 1-08 for K&R
  > Author: Chen, Guan-Yu
  > Created Time: Sun Jan 26 01:24:09 2020
 ************************************************************************/

#include<stdio.h>

int main(int argc, const char *argv[])
{
    int c, nblank, ntab, nline;
    nblank = ntab = nline = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                ++nblank;
                break;
            case '\t':
                ++ntab;
                break;
            case '\n':
                ++nline;
                break;
        }
    }
    printf("blanks: %d\t tabs: %d\t newlines: %d\n", nblank, ntab, nline);
    return 0;
}
