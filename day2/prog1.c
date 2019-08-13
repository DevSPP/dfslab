//Question number 5-Karprekar number

#include <stdio.h>

int main()
{
    int num, i, j, sqr;
    printf("Enter the number:");
    scanf("%d", &num);
    sqr = num * num;
    j = num;
    while (j / 10 > 0)
    {
        j = j / 10;
        i++;
    }
    i++;

    int pow = 1;
    printf("Number of digits: %d \n", i);
    j = 0;
    while (j < i)
    {
        pow = 10 * pow;
        j++;
    }
    printf("10^%d is %d \n", i, pow);
    int sum = (sqr / pow) + (sqr % pow);
    printf("Sum is %d \n", sum);
    if (sum == num)
        printf("Yes! A \"Kaprekar\" Number");
    return 0;
}