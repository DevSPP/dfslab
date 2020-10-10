#include <stdio.h>
#include <string.h>

int main()
{
    float p;
    char *p1;
    scanf("%f", &p);
    printf("%f\n", p);
    getchar(); //eats away \n character
    scanf("%m[^\n]", &p1);
    printf("%ld", strlen(p1));
}