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

    //======Command line arguments====
    // int main(int argc, char *argv[])
    // {
    //     int counter;
    //     printf("Program Name Is: %s", argv[0]);
    //     if (argc == 1)
    //         printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
    //     if (argc >= 2)
    //     {
    //         printf("\nNumber Of Arguments Passed: %d", argc);
    //         printf("\n----Following Are The Command Line Arguments Passed----");
    //         for (counter = 0; counter < argc; counter++)
    //             printf("\nargv[%d]: %s", counter, argv[counter]);
    //     }
    //     return 0;

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
    //=====================File
    // FILE *fp;
    // int ch;
    // fp = fopen("f.bat", "r");
    // ch = getw(fp); // binary data of 4bytes
    // printf("%d", ch);
    // fclose(fp);
    //============scanf caret
    char *x;
    scanf("%m[a-z ^A-Z]", &x);
    printf("%s\n", x);
    scanf("%m[^0]", &x);
    printf("%s", x);

    //=====CONCLUSION======
    //scaff keeps filling of buffer, when you hit enter it stores \n and executes
}
