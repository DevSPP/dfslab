#include <stdio.h>
#include <math.h>

int check(int num, char flag)
{
    int i = num;
    int sum = 0, prod = 1;
    if (num < 10)
    {
        printf("Enter number greater than 10!\n");
        return 0;
    }
    do
    {
        sum = sum + (i % 10);
        prod = prod * (i % 10);
        i = i / 10;

    } while ((i / 10) > 0);

    sum = sum + (i % 10);
    prod = prod * (i % 10);
    sum = sum + prod;
    if (num == sum)
        printf("%d is a Magic Number! \n", num);
    else if (flag)
    {
        printf("Not a Magic Number \n");
    }

    return 0;
}

int main()
{
    int num;

    printf("Enter the value of n:");
    scanf("%d", &num);
    //First Part
    check(num, 1);

    //part 2
    int i, j;
    printf("Enter the number of digits n:");
    scanf("%d", &num);
    i = pow(10, num);
    j = pow(10, (num - 1));
    printf("%d %d \n", i, j);
    for (int n = j; n < i; n++)
    {
        check(n, 0);
    }
}