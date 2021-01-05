/*************************************************************************
  > File Name: 01_ranges_of_variable_types.c
  > Description: Ex. 2-01 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Dec 31 23:24:43 2020
 ************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define max(X) _Generic((X), \
                        char: max_char, \
                        signed char: max_char, \
                        short: max_short, \
                        int: max_int, \
                        long: max_long, \
                        long long: max_llong, \
                        unsigned char: max_uchar, \
                        unsigned short: max_ushort, \
                        unsigned int: max_uint, \
                        unsigned long: max_ulong, \
                        unsigned long long: max_ullong \
                        )(X)

char max_char(char max){
    for (char i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

signed char max_schar(signed char max){
    for (signed char i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

short max_short(short max){
    for (short i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

int max_int(int max){
    for (int i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

long max_long(long max){
    for (long i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

long long max_llong(long long max){
    for (long long i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

unsigned char max_uchar(unsigned char max){
    for (unsigned char i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

unsigned short max_ushort(unsigned short max){
    for (unsigned short i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

unsigned int max_uint(unsigned int max){
    for (unsigned int i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

unsigned long max_ulong(unsigned long max){
    for (unsigned long i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

unsigned long long max_ullong(unsigned long long max){
    for (unsigned long long i = 1; i > max; i <<= 1, ++i) {
        max = i;
    }
    return max;
}

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
    printf("Range of 'double': %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Range of 'long double': %Le to %Le\n\n", LDBL_MIN, LDBL_MAX);

    unsigned long long max;
    printf("Direct Computation Test\n");
    printf("-------------------------\n");
    max = max((char)0);
    printf("Range of 'char': %lld to %lld\n", -max-1, max);
    max = max((signed char)0);
    printf("Range of 'signed char': %lld to %lld\n", -max-1, max);
    max = max((unsigned char)0);
    printf("Range of 'unsigned char': %d to %llu\n\n", 0, max);

    max = max((short)0);
    printf("Range of 'short': %lld to %lld\n", -max-1, max);
    max = max((unsigned short)0);
    printf("Range of 'unsigned short': %d to %llu\n\n", 0, max);

    max = max((int)0);
    printf("Range of 'int': %lld to %lld\n", -max-1, max);
    max = max((unsigned int)0);
    printf("Range of 'unsigned int': %d to %llu\n\n", 0, max);

    max = max((long)0);
    printf("Range of 'long': %lld to %lld\n", -max-1, max);
    max = max((unsigned long)0);
    printf("Range of 'unsigned long': %d to %llu\n\n", 0, max);

    max = max((long long)0);
    printf("Range of 'long long': %lld to %lld\n", -max-1, max);
    max = max((unsigned long long)0);
    printf("Range of 'unsigned long long': %d to %llu\n\n", 0, max);
    return 0;
}
