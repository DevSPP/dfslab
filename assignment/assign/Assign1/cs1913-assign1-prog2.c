/*-----------------------------------
Name: SUBRAT PRASAD PANDA
Roll number: CS1913
Date: 10/08/2019
Program description: ASSIGNMENT 1, QUESTION NUMBER OF 2, Partition of sets and finding AND, XOR
Acknowledgements: Kreher's Algo for partition, (http://www2.denizyuret.com/bib/kreher/donald1999combinatorial/combinatorialA.pdf)
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

unsigned print_arr(unsigned N, unsigned *input, unsigned *rf) //function to print given partition

{
    unsigned x = N, i;
    for (i = 1; i < N; i++) // For ignoring condition when all elements were equal: Single partition
    {
        if (rf[i] != rf[i - 1])
            break;
    }
    if (i < N)
    {
        for (unsigned i = 0; i < N; i++)
        {
            for (unsigned j = 0; j < N; j++)
            {
                if (rf[j] == i)
                {
                    printf("%u ", input[j]);
                    x--;
                }
            }
            if (x > 0)
                printf("-1 ");
        }
        return 0;
    }
}

unsigned func(unsigned N, unsigned *input, unsigned *rf) //function to make xor and and of a given partition
{
    unsigned xor ;
    unsigned and;

    int l = 0, i, m = 0;
    for (i = 1; i < N; i++) // For ignoring condition when all elements were equal: Single partition
    {
        if (rf[i] != rf[i - 1])
            break;
    }

    if (i < N)
    {
        for (unsigned i = 0; i < N; i++)
        {
            for (unsigned j = 0; j < N; j++)
            {
                if (rf[j] == i)
                {
                    //printf("(%u)", input[j]);
                    if (l == 0)
                    {
                        xor = input[j];
                        l = 1;
                    }
                    else
                    {
                        xor = (xor) ^ (input[j]);
                    }
                    //printf("|%u", xor);
                }
            }
            l = 0;
            if (m == 0)
            {
                and = xor;
                m = 1;
            }
            else
            {
                and = (and) & (xor);
            }
            //printf(":%u", and);
        }
        return and;
    }
    else
    {
        return 0;
    }
}

// ----------Test Function
/*void print_a(unsigned N, unsigned *rf)
{
    for (int i = 0; i < N; i++)
    {
        printf("%u ", rf[i]);
    }
}*/

unsigned rgf(unsigned N, unsigned n, unsigned *input, unsigned *rf, unsigned max, unsigned *vmax, int *flag)
{
    if (n == 0) //base case for generating
    {
        if (*flag == 1)
        {
            int r = func(N + 1, input, rf);
            //print_a(N + 1, rf); printf("\n");
            if (r > *vmax)
                *vmax = r;
            return 0;
        }
        if (*flag == 2) // depending on flag it will print the output
        {
            int r = func(N + 1, input, rf);
            if (r == *vmax)
            {
                print_arr(N + 1, input, rf);
                printf("\n");
            }
            return 0;
        }
    }
    // Recusrion call
    for (unsigned i = 0; i <= (max + 1); i++)
    {
        rf[n] = i;
        rgf(N, n - 1, input, rf, ((i > max) ? i : max), vmax, flag);
    }
    return 0;
}

int main()
{

    unsigned *input = (unsigned *)malloc(sizeof(unsigned)); // Initializtion of INPUT pounsigneder----> (unsigned)
    unsigned n = 0;                                         //Number of Inputs
    char temp;                                              //temp variable to detect ENTER press
    do
    {
        input = (unsigned *)realloc(input, sizeof(unsigned) * (n + 1));
        scanf("%u%c", &input[n], &temp);
        n++;

    } while (temp != '\n');
    unsigned *rf = (unsigned *)calloc(n, sizeof(unsigned)); // Creation of same sized memory array for storing INDEX of MAX SUM

    unsigned max = 0, flag = 1;                   //max: to store maximum XOR and AND value, flag: to decide between printing and finding max
    rgf(n - 1, n - 1, input, rf, 0, &max, &flag); // function to generate partion functions
    flag = 2;
    rgf(n - 1, n - 1, input, rf, 0, &max, &flag); // function call to print parition functions
    printf("%u", max);
    free(rf);
    free(input);
    return 0;
    //----------------------------------------------------------------------------
}