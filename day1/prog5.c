#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp; //file with the data

int compare(const void *, const void *); //function for the qsort
char *stringAt(int l)                    //returns the string pointer to a line
{
    char *str = NULL;
    size_t *size;
    size_t a = 0;
    size = &a;
    fseek(fp, 0, SEEK_SET);
    for (int i = 1; i <= l; i++)
        getline(&str, size, fp);
    return str; //str stores a address in heap
}

int compare(const void *elem1, const void *elem2)
{
    int l1 = *(int *)elem1;        // line number
    int l2 = *(int *)elem2;        // line number
    const char *s1 = stringAt(l1); //string at line number l1
    const char *s2 = stringAt(l2); //string at line number l2
    int r = strcmp(s1, s2);        // Alt.: return strcmp(s1, s2);
    free((void *)s1);
    free((void *)s2);
    return r;
}

int main()
{
    fp = fopen("file.txt", "r");
    int array[6] = {1, 2, 3, 4, 5, 6}; //array containing line number

    qsort((void *)array, 6, sizeof(int), compare);

    for (int i = 0; i < 6; i++)
        printf("%d ", array[i]);

    fclose(fp);
}