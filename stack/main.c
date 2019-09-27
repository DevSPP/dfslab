#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

//defaul max size is 5
int main()
{
  STACK *stack1 = initStack(sizeof(int));
  int *ptr = (int *)stack1->elements;

  int a = 20;
  int b = 30;

  printf("%p\n", stack1->elements);
  //printf("%d %d %d\n",ptr[0], ptr[1], ptr[2]);

  push(stack1, &a);
  stackPrint(stack1);
  push(stack1, &b);
  stackPrint(stack1);
  a = 50;
  b = 60;
  push(stack1, &a);
  push(stack1, &b);
  // a = 10;
  // b = 15;
  // push(stack1, &a);
  // push(stack1, &b);
  // stackPrint(stack1);
  // //pop
  // int *c = pop(stack1);
  // free(c);
  // stackPrint(stack1);
  // c = pop(stack1);
  // free(c);
  // stackPrint(stack1);
  // b = 100;
  // push(stack1, &b);
  // stackPrint(stack1);
  freeStack(stack1);
}
