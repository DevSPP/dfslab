#include <stdio.h>

int main()
{
    int a[2][2] = {{1, 2}, {5, 7}};
    int(*p)[];
    p = a;
    printf("%p\n", p);
    printf("%p\n", *p);
    printf("%p\n", a[1]);
    printf("%p\n", &a[1][0]);
    printf("%d\n", *(a[1] + 1));
}
