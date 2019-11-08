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
//=========Alternate

typedef struct tree
{
    int free;
    int max_len;
    DATA *elements;
} BTREE;

BTREE *init_btree();
void insertEnd_bt(BTREE *bt, DATA d);
void insertAt_bt(BTREE *bt, DATA d, int loc); //at particular location
void print_bt(BTREE *bt);
void destroy_bt(BTREE *bt);
#endif // _GTREE_