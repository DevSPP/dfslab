#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1 = fopen("t1.txt", "r+");
    char *store;
    int a[3] = {36, 23, 78};
    //int b[3];
    //printf("%ld", sizeof(a));
    //fread(store, 1, 10, fp1); store needs to be allocated beforehand
    //fwrite(a, sizeof(a), 1, fp1);
    //rewind(fp1);
    //int num = getw(fp1); //get binary data may be integer etc
    //fread(b, sizeof(b), 1, fp1);
    size_t t = 0;
    store = malloc(sizeof(char));
    getline(&store, &t, fp1);
}