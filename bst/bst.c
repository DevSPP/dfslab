#include "bst.h"

TREE init_tree(int n) //tree will be on main stack
{
    TREE t;
    assert(NULL != (t.nodelist = (NODE *)malloc(n * sizeof(NODE)))); //aborts if NULL
    for (int i = 0; i < n ; i++)
        t.nodelist[i].left = i + 1;
    t.max_nodes = n;
    t.free = 0;
    t.root = -1;
    t.num_nodes= 0;
    return t;
}

void insert(TREE *tree, int *rootptr, DATA d)
{
    int size;
    // Increase size if required
    if((tree->num_nodes)==(tree->max_nodes-1))
        { //realloc if more memory is reqired
            size=tree->max_nodes;
            tree->max_nodes*= 2;
            assert(NULL != (tree->nodelist= realloc(tree->nodelist, tree->max_nodes * sizeof(NODE))));
            for (int i = size; i < (tree->max_nodes); i++)
                tree->nodelist[i].left = i + 1;       
        }
   
    int root = *(rootptr);
    int next;
    if (root == -1) {
    // Fress is stored in the left index 
    //assert(tree->num_nodes < tree->max_nodes);
    next = tree->free; //first assign then increment
    tree->free=tree->nodelist[next].left; //Free is moved to next free
    tree->nodelist[next].data = d;
    tree->nodelist[next].left = tree->nodelist[next].right = -1;
    *rootptr = next;
    tree->num_nodes++;
    return;
    }

    if (d.var1 < tree->nodelist[root].data.var1) //introduce compare function here
        insert(tree, &(tree->nodelist[root].left), d);
    else if (d.var1 > tree->nodelist[root].data.var1)
        insert(tree, &(tree->nodelist[root].right), d);
    return;
}

int compare(NODE node, DATA d){
    if (d.var1 < node.data.var1)
        return -1;
    else if (d.var1 > node.data.var1)
        return 1;
    else
        return 0;
    
}

int search(TREE *tree, int root, DATA d)
{
    if (root == -1)
        return -1;
    if (compare(tree->nodelist[root], d) < 0)
        return search(tree, tree->nodelist[root].left, d);
    else if (compare(tree->nodelist[root], d) > 0)
        return search(tree, tree->nodelist[root].right, d);
    else
        return root;
}

void inorder(TREE *tree, int root)
{
    if (root == -1)
        return;
    inorder(tree, tree->nodelist[root].left); //GOTO left
    printf("%d ", tree->nodelist[root].data.var1); //visit the node
    inorder(tree, tree->nodelist[root].right); //GOTO right
    return;
}

void delete(TREE* tree, int* rootptr, DATA d)
{
    int root= *rootptr;

    if (root == -1) //element does not exist
        return; //do nothing
    int cmp = compare(tree->nodelist[root], d);
    //search for elements
    if (cmp < 0)
        delete (tree, &(tree->nodelist[root].left), d);
    else if (cmp > 0)
        delete (tree, &(tree->nodelist[root].right), d);
    else
    {   int next= tree->free;
        if (tree->nodelist[root].left == -1 && tree->nodelist[root].right == -1)
        {
            /* Case I: leaf, just delete */
            *rootptr = -1;
            tree->free=root;
            tree->nodelist[root].left=next;
            tree->nodelist[root].data.var1=0; //proves the item is deleted
            tree->num_nodes--;
            return;
        }
        /* Case II: only one child */
        if (tree->nodelist[root].left == -1)
        {
            *rootptr = tree->nodelist[root].right;
            tree->nodelist[root].right=-1;
            tree->free = root;
            tree->nodelist[root].left = next;
            tree->nodelist[root].data.var1 = 0; //proves the item is deleted
            return;
        }
        if (tree->nodelist[root].right == -1)
        {
            *rootptr = tree->nodelist[root].left;
            tree->nodelist[root].left = -1;
            tree->free = root;
            tree->nodelist[root].left = next;
            tree->nodelist[root].data.var1 = 0; //proves the item is deleted
            return;
        }
        /* Case III: both sub-trees present */
        int s; //index of detached child
        s = detach_successor(tree,root);
        tree->nodelist[root].data = tree->nodelist[s].data; //copy the structure
        //free s
        tree->nodelist[s].right = - 1;
        tree->free = s;
        tree->nodelist[s].left = next;
        tree->nodelist[s].data.var1 = 0;
    }
    return;
}

int detach_successor(TREE *tree, int node)
{
    int child; //send the index of child
    assert(node != -1); //no tree exist
    /* Go to right child, then as far left as possible */
    child = tree->nodelist[node].right;
    if (child == -1) /* no successors */
        return -1;
    if (tree->nodelist[child].left == -1)
    {
        tree->nodelist[node].right = tree->nodelist[child].right;
        return child;
    }
    while (tree->nodelist[child].left != -1)
    {
        node = child;
        child = tree->nodelist[child].left;
    }
    tree->nodelist[node].left = tree->nodelist[child].right;
    return child;
}

void print_pstree(TREE *tree, int root)
{   
    
    if (root != -1)
    {
        fprintf(stderr, "\\pstree{\\TCircle[radius=0.5]{%d}}{\n", tree->nodelist[root].data.var1);
        print_pstree(tree, tree->nodelist[root].left);
        print_pstree(tree, tree->nodelist[root].right);
        fprintf(stderr, "}\n");
    }
    else
        fprintf(stderr, "\\pstree{\\Tn}{} \\pstree{\\Tn}{}");

    return;
}

void print_tree(TREE *tree,int root, int indent)
{
    int i;
    if (root == -1)
        return;
    print_tree(tree, tree->nodelist[root].left, indent + 1);
    putchar('\n');
    for (i = 0; i < indent; i++)
        putchar('\t');
    printf("%d\n", tree->nodelist[root].data.var1);
    putchar('\n');
    print_tree(tree, tree->nodelist[root].right, indent + 1);
    return;
}

void delete_tree(TREE *tree){
    free(tree->nodelist);
    }