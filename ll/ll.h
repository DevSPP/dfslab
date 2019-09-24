#ifndef H_LL
#define H_LL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MSG(x) \
    {              \
        perror(x); \
    }
// struct for stroring data
typedef struct
{
    int var1;
} DATA;
// struct for creating the node
typedef struct node
{
    DATA data;
    struct node *next;
} NODE;

NODE *create_node(DATA);
void push(NODE **, DATA);
void insertAfter(NODE *, DATA);
void append(NODE **, DATA);
void printLL(NODE *);
int lenLL(NODE *);
void insertAt(NODE **, DATA, int);
void delAt(NODE **, int);
void destroyLL(NODE **);

//-----------------------function for alternative ll
// _A is added to all the functions

typedef struct
{
    DATA data;
    int next;
} NODE_A;
typedef struct
{
    int head, free;
    int length, size;
    NODE_A *elements;
} LIST_A;

LIST_A create_list(int);
void insert_A(LIST_A *, DATA, int);
void printLL_A(LIST_A *);

#endif