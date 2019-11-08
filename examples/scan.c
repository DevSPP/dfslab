#include <stdio.h>
#include <stdlib.h>

int main()
{
    // char *b;
    // char x[10];
    // char m[10], n;
    // int i = 0, j;
    // [] does not works with c or s as [] itself is a type of longchar
    // scanf("%[a-z]", x);
    // printf("%s", x);
    // Using scanf
    // while (scanf("%m[A-Z a-z]", &b) && i < 2)
    // {
    //     i = 0, j = 0;
    //     printf("%s\n", b);
    //     scanf("%*m[^a-z A-Z \n]");
    //     i = scanf("%1m[\n]", &m);
    //     j = scanf("%1m[\n]", &n);
    //     i = i + j;
    //     free(b);
    // }

    //---------------printf-string
    // char *b;
    // scanf("%m[a-z]", &b);
    // printf("%s", b);
    // scanf("%m[^a-z]", &b);
    // printf("%s", b);
    // free(b);
    //--false case
    // char *b;
    // b = NULL;
    // scanf("%[^\n]", b);
    // printf("%s", b);
    FILE *fp;
    int ch;
    
    fp = fopen("f.bat", "r");
    ch = getw(fp); // binary data of 4bytes
    printf("%d", ch);
    fclose(fp);
}
