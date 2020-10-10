/*-----------------------------------
Name: SUBRAT PRASAD PANDA
Roll number: CS1913
Date: 11/10/2019
Program description: ASSIGNMENT 2, QUESTION NUMBER OF 3, Greatest multiplication of two list
Acknowledgements: NIL 
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

double d_lim = DBL_MIN * 10000000;
double du_lim = DBL_MAX / 10000000;

void check_limit_val(double *val1, double *val2) //keep checks on bound of val1 and val2
{
    if (*val1 < d_lim || *val2 < d_lim)
    {
        *val1 = *val1 * 1000000000;
        *val2 = *val2 * 1000000000;
    }
    if (*val1 > du_lim || *val2 > du_lim)
    {
        *val1 = *val1 / 1000000;
        *val2 = *val2 / 1000000;
    }
    return;
}

void normalize(unsigned long int *mul1, unsigned long int *mul2, double *val1, double *val2)
{ // to impart all the changes to val2 and val2 resetting mul1 and mul2 to 1
    if (*mul1 != 1 || *mul2 != 1)
    {
        check_limit_val(val1, val2);
        if (*mul1 > *mul2)
        {
            *val1 = *val1 * ((*mul1) / (*mul2));
        }
        else if (*mul1 < *mul2)
        {
            *val2 = *val2 * ((*mul2) / (*mul1));
        }
        //decrease i to consider the missed list value
        *mul1 = 1; // reset of mult result
        *mul2 = 1;
        return;
    }
}

void l_print(double *val1, double *val2) // print the results
{
    if (*val1 == *val2)
        printf("L1 L2");
    else if (*val1 > *val2)
        printf("L1");
    else
        printf("L2");
}

int main()
{
    unsigned long int *list1 = (unsigned long int *)malloc(sizeof(unsigned long int) * 1); // Initializtion of INPUT pointer----> (int)
    unsigned long int *list2 = (unsigned long int *)malloc(sizeof(unsigned long int) * 1);
    int n[3]; //Number of Inputs in the list l1=n[1] and l2=n[2]
    unsigned long int limit = sqrt(ULONG_MAX);

    char temp; //temp variable to detect ENTER press
    //=======================================1. User Input===============================
    unsigned long int *input;
    input = list1;
    for (int i = 1; i <= 2; i++)
    {
        n[0] = 0;
        do //Getting User input
        {
            input = (unsigned long int *)realloc(input, sizeof(unsigned long) * (n[0] + 2));
            scanf("%lu%c", input + n[0], &temp);
            (n[0])++;
        } while (temp != '\n');
        if (i == 1)
        {
            list1 = input;
            input = list2;
        }
        n[i] = n[0];
    }
    list2 = input;
    input = NULL;
    //===============storing the data finish==========

    /* -----TEST prog to print data
    for (int i = 0; i < n[1]; i++)
        printf("%lu ", list1[i]);
    printf("\n");
    for (int i = 0; i < n[2]; i++)
        printf("%lu ", list2[i]); */
    //---------------------------------------------------------------------------------------
    /*==================================LOGIC===============================================
                            list1  (< or > or ==)  list2
        => a1*a2*a3.....am (< or > or ==) b1*b2....* bn , here a and b are numbers of list1 and list2 respectively
        => keep multiplying mul1 = a1*a2*..ak  and mult2= b1*b2...*bj till mul1 value reaches LIMIT (ULONG_MAX)
        => When mul1 or mul2 reaches max limit divide mul1 with mul2(greater of them is numerator)
        => Multiply above result to var1 or var2 which ever side the value is getting multiplied
        => Here, val1=LHS and val2=RHS
        => at the end relation between val1 and val2 is computed

                                mul1 mul2 -> multiplication result
                                val1 val2 ->Division result
        ====================================================================================*/

    //-----------------------------------------2. Multiplication------------------
    int min = (n[1] < n[2]) ? n[1] : n[2];
    unsigned long int mul1 = 1, mul2 = 1; //to store multiplication result
    double val1 = 1, val2 = 1;            // to store division result

    for (int i = 0; i < min; i++)
    {
        // Keeping the value of val1 and val2 under upper  and lower limit
        check_limit_val(&val1, &val2);
        if (mul1 < limit && list1[i] < limit && mul2 < limit && list2[i] < limit)
        {
            mul1 = mul1 * list1[i];
            mul2 = mul2 * list2[i];
        }
        else if (mul1 == 1 && list1[i] > limit && mul2 == 1 && list2[i] > limit)
        {
            if (list1[i] > list2[i])
            {
                val1 = val1 * list1[i] / list2[i];
            }
            else if (list1[i] < list2[i])
            {
                val2 = val2 * list2[i] / list1[i];
            }
        }
        else
        {
            if (mul1 > mul2)
            {
                val1 = val1 * mul1 / mul2;
            }
            else if (mul1 < mul2)
            {
                val2 = val2 * mul2 / mul1;
            }
            i--;      //decrease i to consider the missed list value
            mul1 = 1; // reset of mult result
            mul2 = 1;
        }
    }
    // Changing results to var1 and var2 so that mul1 and mul2 can be reset
    normalize(&mul1, &mul2, &val1, &val2);
    // multiplication done till min of n1 and n2

    //----------------------------------------2. Multiplication after completion of min lenght multiplication
    //------------------------i.if size of list one is larger
    if (n[1] > n[2])
    {
        if (val1 >= val2)
            printf("L1");
        else
        { //multiply till end
            for (int i = min; i < n[1]; i++)
            {
                check_limit_val(&val1, &val2);
                if (mul1 < limit & list1[i] < limit)
                {
                    mul1 = mul1 * list1[i];
                }
                else if (mul1 == 1 && list1[i] > limit)
                {
                    val1 = val1 * list1[i];
                }
                else
                {
                    val1 = val1 * mul1;
                    i--;
                    mul1 = 1;
                }
                //check condition after operation
                if (val1 > val2)
                    break;
            }
            normalize(&mul1, &mul2, &val1, &val2);
            l_print(&val1, &val2);
        }
    }

    //--------------------------------ii. for equals case
    if (n[1] == n[2])
    {
        l_print(&val1, &val2);
    }

    //-------------------------------iii. for length of list2 greater than list1
    if (n[1] < n[2])
    {
        if (val1 <= val2)
            printf("L2");
        else
        { //multiply till end
            for (int i = min; i < n[2]; i++)
            {
                check_limit_val(&val1, &val2);
                if (mul2 < limit & list2[i] < limit)
                {
                    mul2 = mul2 * list2[i];
                }
                else if (mul2 == 1 && list2[i] > 0)
                {
                    val2 = val2 * list2[2];
                }
                else
                {
                    val2 = val2 * mul2;
                    i--;
                    mul2 = 1;
                }
                //check condition after operation
                if (val1 < val2)
                    break;
            }
            normalize(&mul1, &mul2, &val1, &val2);
            l_print(&val1, &val2);
        }
    }

    free(list1);
    free(list2);
}