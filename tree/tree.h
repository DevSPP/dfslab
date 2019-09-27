#ifndef _GTREE_
#define _GTREE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MSG(x) \
    {              \
        perror(x); \
    }

typedef struct data
{
    int var1;
} DATA;

typedef struct btnode
{
    DATA d;
    struct btnode *left, *right;
    //struct treeNode *parent; // This is optional
} BTNODE;

BTNODE *addNode(DATA *);

#endif // _GTREE_