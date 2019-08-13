#include <stdio.h>

#define asize 10
#define bsize 3

int main()
{

    int a[asize] = {1, 2, 3, 2, 3, 1, 1, 2, 3, 5};
    int b[bsize] = {1,
                    2,
                    3};
    int j, count = 0;

    for (int i = 0; i < asize; i++)
    {
        for (j = 0; j < bsize; j++)
        {
            if (a[i + j] != b[j])
            {
                break;
            }
        }
        if (j == bsize)
        {
            count++;
        }
    }
    printf("%d", count);
}
