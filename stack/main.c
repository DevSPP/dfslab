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
  printf("%d %ld\n", ptr[stack1->num_elements - 1], stack1->num_elements);
  push(stack1, &b);
  printf("%d %ld\n", ptr[stack1->num_elements - 1], stack1->num_elements);
  printf(isEmpty(stack1) ? "true" : "false");
  freeStack(stack1);
}
