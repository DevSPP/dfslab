#include <stdio.h>

int main()
{
    unsigned a[] = {3, 5, 7, 2};
    //unsigned b[4][4];

    for (unsigned i = 0; i < 4; i++)
    {
        for (unsigned j = 0; j < 4; j++)
        {
            printf("%d ", a[i] ^ a[j]);
        }
        printf("\n");
    }
}