#include <stdio.h>

int main()
{
    typedef struct
    {
        int a;
        int b;
    } test;
    test p1;
    test **p2;
    test *p3;
    p3 = &p1;
    p2 = &p3;

    scanf("%d", &(**p2).a);
    scanf("%d", &(**p2).b);
    printf("%d %d", p1.a, p1.b);
}