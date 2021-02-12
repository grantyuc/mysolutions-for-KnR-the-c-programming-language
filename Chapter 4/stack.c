/*************************************************************************
  > File Name: stack.c
  > Description: Ex. in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Feb 12 15:18:32 2021
 ************************************************************************/

#include <stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: print the top elements of the stack without popping */
double peek()
{
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* duplicate: duplicate the top element */
void duplicate()
{
    double tmp = peek();
    push(tmp);
}

/* swap: swap the top two elements */
void swap()
{
    if (sp < 2) {
        printf("error: less than two elements in stack");
        return;
    }
    double tmp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = tmp;
}

/* clear: clear the stack */
void clear() 
{
    sp = 0;
}
