#include "stack.h"
//stack follows 1 based indexing
STACK *initStack(size_t element_size)
{
  STACK *new = (STACK *)malloc(sizeof(STACK));
  if (NULL == new)
  {
    printf("Memory Error");
    return NULL;
  }
  new->max_elements = 5;
  new->element_size = element_size;
  new->num_elements = 0;
  new->elements = malloc(element_size * new->max_elements);
  if (new->elements)
    printf("Stack Created; Add=%p \n", new->elements);
  else
  {
    printf("Memory Error\n");
    return NULL;
  }

  return (new);
}

bool isEmpty(STACK *s)
{
  return !(s->num_elements);
}

bool isFull(STACK *s)
{
  return s->max_elements - s->num_elements;
}

void push(STACK *s, void *eptr)
{
  if (isFull)
    //call to extend memory
    //if failed retrn stack overflow null no memory
    printf("%p\n", s->elements + (s->element_size) * (s->num_elements));
  printf("%d\n", *((int *)eptr));
  memcpy((char *)s->elements + (s->element_size) * (s->num_elements), eptr, s->element_size);
  s->num_elements++;
}

//void pop(STACK *s, void *eptr)

void freeStack(STACK *s)
{
  free(s->elements);
  free(s);
  s = NULL;
  printf("Stack Deleted\n");
}
