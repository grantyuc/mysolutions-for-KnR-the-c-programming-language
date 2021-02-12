/*************************************************************************
  > File Name: calc.h
  > Description: Ex. in K&R
  > Author: Chen, Guan-Yu
  > Created Time: Fri Feb 12 15:09:47 2021
 ************************************************************************/

#ifndef _CALC_H
#define _CALC_H
#define NUMBER '0'
void push(double);
double pop();
int getop(char[]);
int getch();
void ungetch(int);
#endif
