#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define err_msg(x) \
    {              \
        perror(x); \
    }

// * // ? ! todo types of comments

typedef struct data
{
    int var1;
} DATA;

typedef struct node
{
    DATA data;
    int left, right;
} NODE;

typedef struct tree
{
    unsigned int num_nodes, max_nodes;
    int root, free; // !index of root
    NODE *nodelist;
} TREE;


// functions bst1
TREE init_tree(int n);

void insert(TREE *tree, int *rootptr, DATA d);
void delete(TREE*, int*, DATA); // ?Tested


//BST-ALT-UTILS
int compare(NODE, DATA); // ?Tested
void inorder(TREE *, int root);
void print_pstree(TREE *, int root); //print to latex // ?Tested
void print_tree(TREE *, int, int);   //print on terminal screen // ?Tested
int search(TREE *, int, DATA);
int detach_successor(TREE *, int); // ?Tested

void delete_tree(TREE*);
#endif /* BST_H */