#include "ll.h"

int main()
{
    /*DATA d;
    d.var1 = 4;
    NODE *head = create_node(d);
    d.var1 = 7;
    push(&head, d);
    d.var1 = 5;
    insertAfter(head, d);
    d.var1 = 11;
    append(&head, d);
    printLL(head);
    printf("len: %d \n", lenLL(head));
    d.var1 = 20;
    insertAt(&head, d, 3);
    printLL(head);
    delAt(&head, 3);
    printLL(head);
    destroyLL(&head);*/
    //normal ll
    DATA d;
    d.var1 = 2;
    LIST_A l = create_list(8);
    printLL_A(&l);
    insert_A(&l, d, 0);
    printLL_A(&l);
    d.var1 = 6;
    insert_A(&l, d, 2);
    printLL_A(&l);
    d.var1 = 10;
    insert_A(&l, d, 1);
    printLL_A(&l);
    d.var1 = 17;
    insert_A(&l, d, 1);
    printLL_A(&l);
    d.var1 = 15;
    insert_A(&l, d, 2);
    printLL_A(&l);
    d.var1 = 20;
    insert_A(&l, d, 0);
    printLL_A(&l);
}
