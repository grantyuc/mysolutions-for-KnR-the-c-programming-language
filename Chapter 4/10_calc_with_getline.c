/*************************************************************************
  > File Name: 10_calc_with_getline.c
  > Description: Ex. 4.10 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Thu Feb 18 13:19:48 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>
#include "stack.c"
int getop(char s[], char **pline);
#define NUMBER 0
#define MAXOP 100 /* max size of operand or operator */
#define MAXLEN 1000 /* max length of line */

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;        
    }
    s[i] = '\0';
    return i;
}

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP], line[MAXLEN];
    char *ptr;
    double var[27] = {0}; /* variables: ans, A-Z */
    while (get_line(line, MAXLEN)) {
        ptr = line;
        while ((type = getop(s, &ptr)) != EOF) {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '%':
                    op2 = pop();
                    if (op2 != 0.0)
                        push((int)pop() % (int)op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case 's':
                    push(sin(pop()));
                    break;
                case 'e':
                    push(exp(pop()));
                    break;
                case 'p':
                case '^':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case '\n':
                    var[0] = pop();
                    printf("\t%.8g\n", var[0]);
                    if (!empty()) {
                        printf("warning: stack is not empty\n");
                    }
                    break;
                case '>': // store in: for example,  4 > A means A = 4
                    type = getop(s, &ptr);
                    if (!isupper(type)) {
                        printf("error: unknown variable name %s\n", s);
                        break;
                    }
                    getop(s, &ptr); // skip '\n'
                    var[type - 'A' + 1] = pop();
                    printf("\t%c == %.8g\n", type, var[type - 'A' + 1]);
                    if (!empty()) {
                        printf("warning: stack is not empty\n");
                    }
                    break;
                default:
                    if (isupper(type)) {
                        push(var[type - 'A' + 1]);
                    }
                    else if (type == '_') {
                        push(var[0]);
                    }
                    else
                        printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }
    return 0;
}
