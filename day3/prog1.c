#include <stdio.h>

#define max 4

int main()
{

    char txt[] = "qwe";
    char strs[max][50] = {0};

    for (int i = 0; i < max; i++)
    {
        printf("Enter:");
        scanf("%s", strs[i]);
    }

    int i = 0, b = 0, j = 0, k = 0, flag = 1;

    while (k < max)
    {

        int rslt[50] = {0};
        b = 0;
        j = 0;
        i = 0;

        while (strs[k][i] != '\0')
        {
            j = 0;
            while (txt[j] != '\0')
            {

                if (strs[k][i] == txt[j])
                {
                    rslt[b] = j;
                    b++;
                }
                j++;
            }
            i++;
        }
        //Array order check
        int q = 0, count = rslt[0];
        while (q < b)
        {
            if (rslt[q] >= count)
            {
                if (rslt[q] > (count + 1))
                {
                    count = rslt[q];
                }
            }
            else
            {
                printf("False \n");
                flag = 0;
                break;
            }

            q++;
        }
        if (q == b)
            printf("True \n");
        //new row start
        k++;
    }
    printf("-------------");
    if (flag == 1)
        printf("True");
    else
        printf("False");
}
