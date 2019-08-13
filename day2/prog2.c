#include <stdio.h>

int incr(int a, int *arr)
{
    arr[a] = arr[a] + 1;
    if (arr[a] > 9)
    {
        arr[a] = 0;
        if (a >= 0)
        {
            incr((a - 1), arr);
        }
        return 1;
    }

    return 1;
}

int printarr(int n, int *arr)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        printf(".%d", arr[i]);
        sum = sum + arr[i];
    }
    printf("\n");
    return sum;
}

int main()
{
    int u, l, n;
    printf("Enter the value of n:");
    scanf("%d", &n);
    printf("Enter the value of Upper bound:");
    scanf("%d", &u);
    printf("Enter the value of lower bound:");
    scanf("%d", &l);
    n = n - 2;

    while (l <= u)
    {
        int arr[100] = {0};
        int check = 0;
        if (l == u)
        {
            printf("%d", l);
            printarr(n, arr);
            break;
        }

        while (check < (9 * (n + 1)))
        {
            printf("%d", l);
            check = printarr(n, arr);
            incr(n, arr);
        }
        l++;
    }
}