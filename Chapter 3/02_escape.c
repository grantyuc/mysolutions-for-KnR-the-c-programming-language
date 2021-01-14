/*************************************************************************
  > File Name: 02_escape.c
  > Description: Ex. 3-2 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Jan 14 21:12:56 2021
 ************************************************************************/

#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i, ++j) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            case '\r':
                t[j++] = '\\';
                t[j] = 'r';
                break;
            case '\v':
                t[j++] = '\\';
                t[j] = 'v';
                break;
            case '\\':
                t[j++] = '\\';
                t[j] = '\\';
                break;
            case '\?':
                t[j++] = '\\';
                t[j] = '\?';
                break;
            case '\'':
                t[j++] = '\\';
                t[j] = '\'';
                break;
            case '\"':
                t[j++] = '\\';
                t[j] = '\"';
                break;
            default:
               t[j] = s[i]; 
        }
    }
    t[j] = s[i];
}

enum state {DEFAULT, LISTEN};

void escape_inv(char s[], char t[])
{
    int i, j;
    int listen = DEFAULT;
    for (i = j = 0; s[i] != '\0'; ++i) {
       if (s[i] == '\\' && !listen) {
           listen = LISTEN;
       } else {
           if (listen) {
               switch (s[i]) {
                   case 'n':
                       t[j++] = '\n';
                       break;
                   case 't':
                       t[j++] = '\t';
                       break;
                   case 'r':
                       t[j++] = '\r';
                       break;
                   case 'v':
                       t[j++] = '\v';
                       break;
                   case '\\':
                       t[j++] = '\\';
                       break;
                   case '\?':
                       t[j++] = '\?';
                       break;
                   case '\'':
                       t[j++] = '\'';
                       break;
                   case '\"':
                       t[j++] = '\"';
                       break;
                   default:
                       //escape sequence error
                       break;
               }
           } else {
               t[j++] = s[i];
           }
           listen = DEFAULT;
       } 
    }
    t[j] == s[i];;
}

int main(int argc, const char *argv[])
{
    char s[1<<7] = "This is a newline '\n', a tab '\t', and a vertical tab '\v'. That's all.";
    char t[1<<7];
    printf("Escape string: %s\n", s);
    escape(s, t);
    printf("Visible: %s\n", t);
    escape_inv(t, s);
    printf("Invisible again: %s\n", s);
    return 0;
}
