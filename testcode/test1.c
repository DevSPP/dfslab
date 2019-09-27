#include <stdio.h>

int main()
{
    FILE *fp1 = fopen("t1.txt", "r+");
    FILE *fp2 = fopen("t2.txt", "r+");
    int a = ftell(fp1), b = ftell(fp2);
    char store;
    char store2;
    store = getc(fp1);
    store2 = getc(fp2);

    if (feof(fp1))
        printf("end of file");
    if (feof(fp1))
        printf("end of file");
}