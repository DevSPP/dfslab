//prog4
#include <stdio.h>
#include <math.h>

int main()
{
    float x, y;
    int m, n;
    printf("Enter the value of x:");
    scanf("%f", &x);
    printf("Enter the value of y:");
    scanf("%f", &y);
    printf("Enter the value of m:");
    scanf("%d", &m);
    printf("Enter the value of n:");
    scanf("%d", &n);
    //a
    if ((x + y) - (int)(x + y) == 0)
        printf("The addition is integer \n");
    //b
    if (x > y)
    {
        if (m < x && m > y)
            printf("m lies between x and y \n");
        else
            printf("m is outside. \n");
    }
    else
    {
        if (m < y && m > x)
            printf("m lies between x and y \n");
        else
            printf("m is outside. \n");
    }

    //c
    if (m == (int)x)
        printf("Yes m is equal to integer part of %f \n", x);

    //d
    if ((int)x >= 3 && (x - (int)x) < 0.3)
        printf("Yes! \n");
    //e
    if (((m & 1) == 0 && (n & 1) == 0) || ((m & 1) != 0 && (n & 1) != 0))
        printf("Same parity \n");
    else
    {
        printf("Not same parity");
    }

    //f
    float sqr = sqrt(m);
    if ((sqr - (int)sqr) == 0)
        printf("Perfect Square \n");

    return 0;
}