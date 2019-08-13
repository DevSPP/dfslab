#include <stdio.h>

#define asize 6
#define bsize 3

int main()
{

    int a[asize] = {1, 3, 4, 9, 9, 14};
    int b[bsize] = {9,
                    11,
                    17};
    int i = 0, k = 6, m = 0, n = 0;
    int small = 0;

    while (i < k)
    {
        if (m == asize)
        {
            m = asize - 1;
        }
        if (n == bsize)
        {
            n = bsize - 1;
        }
        if (a[m] < b[n])
        {
            small = a[m];
            printf("|%d", small);
            m++;
            i++;
        }
        else if (b[n] < a[m])
        {
            small = b[n];
            printf("|%d", small);
            n++;
            i++;
        }
        else if (b[n] == a[m])
        {
            small = b[n];
            i++;
            printf("|%d(%d)", small, i);
            i++;
            printf("|%d", small);
            n++;
            m++;
        }
        printf("(%d)", i);
    }
    printf("):----> %d", small);
    return 0;
}
