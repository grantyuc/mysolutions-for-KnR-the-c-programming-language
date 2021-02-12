/*************************************************************************
  > File Name: 04_stack_operation.c
  > Description: Ex. 4.04 in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Feb 12 19:18:58 2021
 ************************************************************************/

#include <stdio.h>
#include "stack.c"

int main(int argc, char *argv[])
{
    printf("stack: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
        push(i);
    }
    printf("\n");
    printf("peek(): %f\n", peek());
    printf("pop(): %f\n", pop());
    duplicate();
    printf("duplicate()\n");
    printf("pop(): %f\n", pop());
    printf("peek(): %f\n", peek());
    printf("swap()\n");
    swap();
    printf("pop(): %f\n", pop());
    printf("pop(): %f\n", pop());
    printf("clear()\n");
    clear();
    printf("push 4\n");
    push(4);
    printf("pop(): %f\n", pop());
    printf("peek(): %f\n", peek());
    return 0;
}
