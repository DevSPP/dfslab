#ifndef H_HEAP
#define H_HEAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MSG(x) \
    {              \
        perror(x); \
    }
//index 1 based heap
// building max heap
typedef struct
{
    size_t element_size;                  // Generic implementation
    unsigned int num_allocated, num_used; // Keep track of the size
    void *array;                          // Using one-based indexing
    int (*comparator)(void *, int, int);  // Returns -ve, 0, or +ve Compare two numbers
} HEAP;

void init_Heap(HEAP *, size_t, int (*)(void *, int, int));
void deleteMax(HEAP *, void *max);
void getMax(HEAP *, void *max);
void insert(HEAP *, void *x);
void build_heap(HEAP *, void *A, size_t, size_t, int (*)(void *, int, int));
int compareInt(void *array, int, int);
void destroy(HEAP *);
void heapsort(HEAP *, void *A, size_t, size_t, int (*)(void *, int, int));

#endif