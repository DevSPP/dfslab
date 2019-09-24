#include "ll.h"

NODE *create_node(DATA d)
{
    NODE *nptr;
    if (NULL == (nptr = (NODE *)malloc(sizeof(NODE))))
        ERR_MSG("out of memory");
    nptr->data = d; // struct elements can be compared but can be assigned
    nptr->next = NULL;
    return nptr;
}

void push(NODE **head, DATA d)
{                                //head is stored in MAIN data stack
    NODE *temp = create_node(d); // Create new node
    /* Make next of new node as head */
    temp->next = (*head);
    /* Move the head to point to the new node */
    (*head) = temp;
}

void insertAfter(NODE *prev_node, DATA d)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    NODE *temp = create_node(d);

    /* 3. Make next of new node as next of prev_node */
    temp->next = prev_node->next;

    /* 4. move the next of prev_node as new_node */
    prev_node->next = temp;
}

void append(NODE **head, DATA d)
{
    /* 2. allocate new node */
    NODE *temp = create_node(d);
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    NODE *last = *head;
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    /* 6. Change the next of last node */
    last->next = temp;
    return;
}

void printLL(NODE *head)
{
    unsigned count = 1;
    printf("________________________________\n");
    printf(" n %10s %12s\n", "data", "ptr");
    printf("--------------------------------\n");
    while (head != NULL)
    {
        printf(">%d %9d %3s %p\n", count, (head->data).var1, " ", head->next);
        head = head->next;
        count++;
    }
}

int lenLL(NODE *head)
{
    unsigned count = 0;
    while (head != NULL)
    {
        count++; // count till end node
        head = head->next;
    }
    return count;
}

// Position is one 1 based
void insertAt(NODE **head, DATA d, int p) //Add of head is required
{
    unsigned count = 1;

    if (p == 1)
        push(head, d); // for p=1 push it at first
    else
    {
        NODE *h = *head;
        while (h != NULL && count < p - 1)
        {
            count++; // count till end node
            h = h->next;
        }
        insertAfter(h, d); //insert after the a particluar node
    }
}

void delAt(NODE **head, int p)
{
    unsigned count = 1;
    if (*head == NULL)
    {
        printf("List Empty");
        return;
    }
    NODE *ptr = *head;
    NODE *temp;
    if (p == 1) //delete single node at position 1
    {
        *head = (*head)->next;
        free(ptr);
        return;
    }
    else
    {
        while ((ptr != NULL) && count < p)
        {
            count++;
            temp = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL)
            printf("Location not exist");
        else
        {
            temp->next = ptr->next;
            free(ptr);
        }
    }
}

void destroyLL(NODE **head)
{
    while (*head != NULL)
        delAt(head, 1);
    return;
}

//============================Alternative Implementation========
//- 0 based counting
// -Create List
LIST_A create_list(int n)
{
    int i;
    LIST_A l;
    if (NULL == (l.elements = (NODE_A *)malloc(n * sizeof(NODE))))
        ERR_MSG("out of memory")
    for (i = 0; i < n - 1; i++)
        l.elements[i].next = i + 1;
    l.elements[n - 1].next = -1; //last loacation is -1
    l.size = n;
    l.free = 0;
    l.head = -1;
    l.length = 0;
    return l;
}

void insert_A(LIST_A *l, DATA d, int p) //insertion after a p-th node
//self loop at the end node
{ /* insert d in front of node */
    int position = l->free;
    int index = l->head;
    int count = 0;
    if (l->head == -1)
    { //list is empty
        l->free = l->elements[l->free].next;
        l->elements[position].data = d;
        l->head = position;
        l->length++;
        return;
    }

    if (-1 == position)
    { //when it gets full
        l->size *= 2;
        if (NULL == (l->elements = realloc(l->elements, l->size * sizeof(NODE_A))))
            ERR_MSG("out of memory");
        l->free = l->size / 2;
        for (int i = l->size / 2; i < l->size - 1; i++)
            l->elements[i].next = i + 1;
        l->elements[l->size - 1].next = -1;
        position = l->free;
    }

    if (p == 0)
    { //node added to head position
        l->elements[position].data = d;
        l->elements[position].next = l->head;
        l->head = position;
        l->length++;
        return;
    }

    while (count < p && count < l->length)
    {
        count++;
        index = l->elements[index].next;
    }
    l->free = l->elements[l->free].next;
    l->elements[position].data = d;
    l->elements[position].next = l->elements[index].next;
    if (index != position)
        l->elements[index].next = position;
    l->length++;
} //self loop at the end node

void printLL_A(LIST_A *l)
{
    unsigned count = 0;
    NODE_A *hd = l->elements;

    printf("___________________________\n");
    printf(" n %8s %8s\n", "data", "next");
    printf("---------------------------\n");
    while (count < l->size)
    {
        printf(">%d %6d %6s %d", count, hd[count].data.var1, " ", hd[count].next);
        if (count == l->head)
            printf(" (head)\n");
        else if (count == l->free)
            printf("<<(free)\n");
        else
            printf("\n");
        count++;
    }
}
