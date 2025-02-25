#ifndef _GSTACK_
#define _GSTACK_

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERR_MSG(x) \
    {              \
        perror(x); \
    }

typedef struct
{
    size_t element_size, num_elements, max_elements;
    void *elements;
} STACK;

STACK *initStack(size_t element_size);
void freeStack(STACK *s);
bool isEmpty(STACK *s);
void push(STACK *s, void *eptr);
void *pop(STACK *s);
void stackPrint(STACK *s); //for prinint int only

#endif // _GSTACK_