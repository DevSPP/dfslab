#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1 = fopen("t1.txt", "r+");
    FILE *fp2 = fopen("t2.txt", "r+");
    int a = ftell(fp1), b = ftell(fp2);
    char store;
    char store2;
    store = getc(fp1);
    store2 = getc(fp2);
    while ((feof(fp1) == 0) || (feof(fp2) == 0))
    {
        if (store == EOF)
        {
            fseek(fp1, 0, SEEK_END);
            fputc(store2, fp1);
            fseek(fp2, -1, SEEK_CUR);
            fputc('\0', fp2);
        }
        else if (store2 == EOF)
        {
            fseek(fp2, 0, SEEK_END);
            fputc(store, fp2);
            fseek(fp1, -1, SEEK_CUR);
            fputc('\0', fp1);
        }
        else
        {
            fseek(fp1, -1, SEEK_CUR);
            fseek(fp2, -1, SEEK_CUR);
            fputc(store2, fp1);
            fputc(store, fp2);
        }
        store = getc(fp1);
        store2 = getc(fp2);
    }

    fclose(fp1);
    fclose(fp2);
}