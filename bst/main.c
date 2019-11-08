#include "bst.h"

int main(int ac, char *av[])
{
    TREE t;
    t = init_tree(4);
    DATA d1,d2,d3;
    d1.var1=2;
    insert(&t,&(t.root),d1);
    d1.var1=6;
    insert(&t,&(t.root),d1);
    d1.var1=5;
    insert(&t,&(t.root),d1);

    // for (int i = 0; i < t.max_nodes; i++)
    // {
    //     printf("Data: %d Left: %d Right: %d \n",t.nodelist[i].data.var1,t.nodelist[i].left,t.nodelist[i].right);
    // }
    d1.var1=7;
    insert(&t,&(t.root),d1);
    d1.var1=19;
    insert(&t,&(t.root),d1);
    // for (int i = 0; i < t.max_nodes; i++)
    // {
    //     printf("Data: %d Left: %d Right: %d \n",t.nodelist[i].data.var1,t.nodelist[i].left,t.nodelist[i].right);
    // }
    // todo:--------------------------- TESTING FUNCTION EXAMPLE
    // !Done: print_pstree(&t,t.root);
    // !Done: print_tree(&t, t.root, 0);
    // !delete(&t,&(t.root),d1);
    // !print_pstree(&t, t.root);
    // !printf("Search: %d", search(&t, t.root, d1));
    // !inorder(&t, t.root);
    delete_tree(&t);
    return 0;
}
