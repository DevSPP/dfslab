#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("file.txt", "r");
    char *str = NULL;
    size_t *size;
    size_t a = 0;
    size = &a;
    for (int i = 1; i <= 3; i++)
        getline(&str, size, fp);
    printf("%s%ld", str, a);
    free(str);
    fclose(fp);
}