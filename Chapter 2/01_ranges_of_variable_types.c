/*************************************************************************
  > File Name: 01_ranges_of_variable_types.c
  > Description: Ex. 2-01 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Dec 31 23:24:43 2020
 ************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, const char *argv[])
{
    printf("From Standard Headers\n");
    printf("-------------------------\n");
    printf("Range of 'char': %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of 'signed char': %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of 'unsigned char': %d to %d\n\n", 0, UCHAR_MAX);

    printf("Range of 'short': %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of 'unsigned short': %d to %d\n\n", 0, USHRT_MAX);

    printf("Range of 'int': %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of 'unsigned int': %d to %u\n\n", 0, UINT_MAX);

    printf("Range of 'long': %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of 'unsigned long': %d to %lu\n\n", 0, ULONG_MAX);

    printf("Range of 'long long': %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Range of 'unsigned long long': %d to %llu\n\n", 0, ULLONG_MAX);

    printf("Range of 'float': %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of 'double': %e to %e\n\n", DBL_MIN, DBL_MAX);

    unsigned long long max;
    printf("Direct Computation Test\n");
    printf("-------------------------\n");
    for (char i = 0; i >= 0; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'char': %lld to %lld\n", -max-1, max);
    for (signed char i = 0; i >= 0; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'signed char': %lld to %lld\n", -max-1, max);
    for (unsigned char i = 1; i != max; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'unsigned char': %d to %llu\n\n", 0, max);

    for (short i = 0; i >= 0; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'short': %lld to %lld\n", -max-1, max);
    for (unsigned short i = 1; i != max; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'unsigned short': %d to %llu\n\n", 0, max);

    for (int i = 0; i >= 0; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'int': %lld to %lld\n", -max-1, max);
    for (unsigned int i = 1; i != max; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'unsigned int': %d to %llu\n\n", 0, max);

    for (long i = 0; i >= 0; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'long': %lld to %lld\n", -max-1, max);
    for (unsigned long i = 1; i != max; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'unsigned long': %d to %llu\n\n", 0, max);

    for (long long i = 0; i >= 0; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'long long': %lld to %lld\n", -max-1, max);
    for (unsigned long long i = 1; i != max; i <<= 1, ++i) {
        max = i;
    }
    printf("Range of 'unsigned long long': %d to %llu\n\n", 0, max);
    return 0;
}
