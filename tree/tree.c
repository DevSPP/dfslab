#include "tree.h"

BTNODE *addNode(DATA *d)
{
    BTNODE *node;
    if (NULL == (node = (BTNODE *)malloc(sizeof(BTNODE))))
        ERR_MSG("out of memory");
    node->d = *d;
    // Initialize left and right child as NULL
    node->left = NULL;  //left child
    node->right = NULL; //right child
    return (node);
}