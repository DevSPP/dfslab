#include <stdio.h>

int main()
{

    int a;
    printf("Enter the number:");
    scanf("%d", &a);
    int i = a;
    int count = 0;
    while (i > 0)
    {
        count = count + i / 5;
        i = i / 5;
    }
    printf("Number of trailing zero in %d! is \"%d\".", a, count);
}