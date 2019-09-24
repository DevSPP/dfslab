#include "heap.h"

int main()
{
    HEAP demo;
    int A[7] = {0, 2, 5, 4, 7, 3, 9};
    build_heap(&demo, A, sizeof(int), 6, compareInt);
    heapsort(&demo, A, sizeof(int), 6, compareInt);
}
