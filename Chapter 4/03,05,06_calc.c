/*************************************************************************
  > File Name: 03,05,06_calc.c
  > Description: Ex. 4.3, 4.5, 4.6 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Feb 12 15:37:03 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>
#include "calc.h"
#define MAXOP 100 /* max size of operand or operator */

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    double var[27] = {0}; /* variables: ans, A-Z */
    while ((type = getop(s)) != EOF) {
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
                type = getop(s);
                if (!isupper(type)) {
                    printf("error: unknown variable name %s\n", s);
                    break;
                }
                getop(s); // skip '\n'
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
    return 0;
}
