#include "tree.h"
static int extend_mem(BTREE *);

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

//===============ALTERNATE- ARRAY BASED================= //index 1 based tree

//all the data stored on heap

BTREE *init_btree() //initialize tree once
{
    BTREE *temp;
    temp = malloc(sizeof(BTREE));
    temp->free = 1; //0 is left
    temp->max_len = 5;
    if (NULL == (temp->elements = (DATA *)malloc(temp->max_len * sizeof(DATA))))
        ERR_MSG("out of memory")
    return temp;
}

static int extend_mem(BTREE *bt)
{
    bt->max_len *= 2;
    bt->elements = realloc(bt->elements, sizeof(DATA) * bt->max_len);
    if (bt->elements)
        printf("Tree Extended\n");
    else
    {
        printf("Memory Error\n");
        return 0;
    }
    return 1;
} // returns 1 in success and 0 failure

void insertEnd_bt(BTREE *bt, DATA d)
{
    if (bt->free == bt->max_len)
    {
        if (!extend_mem(bt))
        {
            printf("Stack Overflow\n");
            return;
        }
    }
    bt->elements[bt->free] = d;
    ++bt->free;
}

void insertAt_bt(BTREE *bt, DATA d, int loc)
{
    if (loc >= bt->free)
    {
        printf("reached End of tree");
    }
    bt->elements[loc] = d;
}

void print_bt(BTREE *bt)
{
    int i = 1;
    while (i < bt->free)
    {
        printf("%d | ", bt->elements[i].var1);
        i++;
    }
    printf("\n");
    return;
}

void destroy_bt(BTREE *bt)
{
    free(bt->elements);
    free(bt);
    bt = NULL;
    printf("Tree Deleted\n");
}