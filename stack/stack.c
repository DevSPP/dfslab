#include "stack.h"
//stack follows 1 based indexing
//stack is created on the heap

static int extend_mem(STACK *);

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
  return !(s->max_elements - s->num_elements);
}

static int extend_mem(STACK *s)
{
  s->max_elements *= 2;
  s->elements = realloc(s->elements, s->element_size * s->max_elements);
  if (s->elements)
    printf("Stack Extended\n");
  else
  {
    printf("Memory Error\n");
    return 0;
  }
  return 1;
}

void push(STACK *s, void *eptr)
{
  if (isFull(s))
  {
    if (!extend_mem(s))
    {
      printf("Stack Overflow\n");
      return;
    }
  }
  memcpy((char *)s->elements + (s->element_size) * (s->num_elements), eptr, s->element_size);
  s->num_elements++;
}

void *pop(STACK *s)
{
  if (isEmpty(s))
  {
    printf("List Empty");
    return NULL;
  }
  else
  {
    void *eptr = malloc(s->element_size);
    memcpy(eptr, (char *)s->elements + (s->element_size) * (s->num_elements - 1), s->element_size);
    --(s->num_elements);
    return eptr;
  }
}

void freeStack(STACK *s)
{
  free(s->elements);
  free(s);
  s = NULL;
  printf("Stack Deleted\n");
}

//print integers

void stackPrint(STACK *s)
{
  if (isEmpty(s))
  {
    printf("Stack Empty");
    return;
  }
  int count = 0;
  printf("____________________\n");
  printf(" n %10s\n", "data");
  printf("--------------------\n");
  while (count < s->num_elements)
  {
    printf(">%-3d %9d", count + 1, *(int *)((s->elements) + (sizeof(int) * count)));
    if (count + 1 == s->num_elements)
      printf("<(top)");
    printf("\n");
    count++;
  }
}
