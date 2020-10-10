/*-----------------------------------
Name: SUBRAT PRASAD PANDA
Roll number: CS1913
Date: 10/08/2019
Program description: ASSIGNMENT 1, QUESTION NUMBER OF 3, To find max sum of contiguous subset
Acknowledgements: Wikipedia for Kadane's algorithms, 
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /****************** NAME OF VARIABLES***************************
       ** n - Number of Inputs 
       ** input[]- input array of integers
       ** check[] - temp array to check max sum
       ** max_sum - maximum sum
       ** min_len - Minimum length of sub array with maximum sum
       *************************END***********************************/
    //---------------------Part 1. Taking User Input using dynamic memory allocation------------------------
    int *input = (int *)malloc(sizeof(int) * 1); // Initializtion of INPUT pointer----> (int)
    int n = 0;                                   //Number of Inputs
    char temp;                                   //temp variable to detect ENTER press

    do //Getting User input
    {
        input = (int *)realloc(input, sizeof(int) * (n + 1));
        scanf("%d%c", &input[n], &temp);
        n++;

    } while (temp != '\n');
    int *check = (int *)calloc(n, sizeof(int)); // Creation of same sized memory array for storing INDEX of MAX SUM
    //--------------------------------------END of Part 1-------------------------------------------------

    //----------------------- Part 2- Kadane's Algorithm to find MAX contigious subset sum----------------
    check[0] = input[0];        //*check ->array initialization with first element assignment
    int max_sum = check[0];     //Maximum sum initialization
    for (int i = 1; i < n; i++) //Implementation of Kadane's Algorithm to find Max contiguous subset sum
    {
        check[i] = input[i] + check[i - 1];
        if (input[i] > check[i])
            check[i] = input[i]; // check[i] = maximum(input[i] or check[i-1]+input[i])
        if (check[i] > max_sum)
            max_sum = check[i];
    } // --------------------------------END Part 2-------------------------------------------

    //-----Part 3- Search for subset arrays having max_sum and storing of subset array length information in the array CHECK-------
    int min_len = n; // minimimum length of subset array with maximum sum
    int sum_temp;    // temp sum variable to search the subset array length.
    //eg X X X X X 2 X , then 5th element is the end of sub-array and 5-2=3 is the start position of sub-array.
    for (int i = 0; i < n; i++)
    {
        int j = i;
        sum_temp = max_sum;
        if (check[i] == max_sum)
        {
            while (sum_temp != 0)
            {
                sum_temp = sum_temp - input[j];
                j--;
            }
            check[i] = (i == j) ? (i - j) : (i - (j + 1));                     // Storing the length of subarray in the array CHECK.
            min_len = (check[i] < min_len) ? (min_len = check[i]) : (min_len); // searching minimum length subarray
        }
        else
        {
            check[i] = -1; // storing -1 at all other places eg -1 -1 -1 3 -1 -1 where 3 is the length of subarray.
        }

    } //------------------------------------END Part3------------------------------------------

    //---------------------------------Part 4 Printing of results------------------------------
    for (int i = 0; i < n; i++)
    {
        if (check[i] == min_len)
        {
            printf("%d %d\n", i - min_len, i);
        }
    }
    printf("%d\n", max_sum);
    // release the memory
    free(input);
    free(check);

    //******************************************** End *****************************************
}