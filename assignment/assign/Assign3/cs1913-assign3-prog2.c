/*-----------------------------------
Name : SUBRAT PRASAD PANDA
Roll number : CS1913
Date : 01/11/2019
Program description : ASSIGNMENT 3, Question 2- Finding prime factors of a number and searching in the array 
Acknowledgements : NIL
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define err_msg(x) \
    {              \
        perror(x); \
        exit(0);   \
    }

//=======================================FUNCTIONS USED================================
int comparator(const void *, const void *);
int binarySearch(int *, int, int, int);
int search_number(int user_arr[], int block_arr[], int N, int num1, int num2); //function to search the number and block the numbers if seen before;
int find_prime_factor(int);                                                    //returns the unique prime number if exists or return -1 in case of non-existence
int binarySearch(int *, int, int, int);
/*==========================================LOGIC=======================================
        1. There is unique 2 prime factors of the numbers in coeff_array
        2. One of them should be less than sqrt(given coefficient) which should be UNIQUE between {2-sqrt(given coefficient)}
        3. The uniqueness of prime factor below sqrt(given coefficient) is the key concept of this program
        4. Once one unique prime factor is found, it will be checked in set_S using BINARY SEARCH        
============================================END========================================*/
int main()
{                //--------------------------------1. TAKING USER INPUT-------------------------------
    int n_coeff; //number of coefficients
    scanf("%d", &n_coeff);
    if (n_coeff == 0)
        err_msg("Enter valid inputs");
    int coeff_array[n_coeff];
    for (int i = 0; i < n_coeff; i++)
        scanf("%d", &coeff_array[i]); //Scaning the coefficients

    //--------------Getting User input for set_S
    int *set_S = (int *)malloc(sizeof(int)); // Initializtion of INPUT pointer----> (int)
    int N = 0;                               //Number of Inputs
    char temp;                               //temp variable to detect ENTER press
    do
    {
        set_S = (int *)realloc(set_S, sizeof(int) * (N + 1));
        scanf("%d%c", &set_S[N], &temp);
        if (set_S[N] < 1)
            err_msg("invalid inputs: Only positive input allowed");
        N++;

    } while (temp != '\n');
    qsort((void *)set_S, N, sizeof(set_S[0]), comparator); // O(nlogn)
    int block_arr[N];                                      //Initilize array to block numbers from searching, used to block repeatition in searching
    memset(block_arr, 0, sizeof(block_arr));               // set array to 0

    //-------------------------------------2.Find 2 unique prime factors (if exist) of numbers from coeff_array-----------
    int pFactor;
    int pFactor2;
    int flag = 1;
    for (int i = 0; i < n_coeff; i++)
    {
        pFactor = find_prime_factor(coeff_array[i]);
        if (pFactor == -1) //function returns one if no factors found
        {
            printf("FALSE\n"); //No prime tuple doesn't exist for the given number
            return 0;
        }
        else
        {
            pFactor2 = coeff_array[i] / pFactor;                          //second number
            flag = search_number(set_S, block_arr, N, pFactor, pFactor2); // search two prime factors if available or not in set_S
            if (flag == -1)
            {
                printf("FALSE\n"); //No prime tuple exist for the given number
                return 0;
            }
        }
    }
    printf("TRUE\n"); //Reached till end after exhaustive checks, hence true
    return 0;
}

//===========================================FUNCTION DEFINITIONS===============================
// Function 1
int find_prime_factor(int num)
{
    int count = 0;   //to count number of divisiors
    int result = -1; // to store the result
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            result = i;
            count++;
        }
        if (count == 2)
            return -1; // in case of failure to find unique prime factor return -1
    }
    return result; // return result in case unique prime is found
}

// Function 2
int search_number(int user_arr[], int block_arr[], int N, int num1, int num2)
{
    int index1, index2;
    index1 = binarySearch(user_arr, 0, N - 1, num1); //binary search the number
    index2 = binarySearch(user_arr, 0, N - 1, num2);
    if (index1 == -1 || index2 == -1)
        return -1; //when the number 1 or number 2 is not found
    else
    {
        if (block_arr[index1] != 0 || block_arr[index2] != 0)
            return -1; //When any of the number is used before hand
        else
        {
            block_arr[index1] = 1; //Blocking the prime factors not to get used in future calls
            block_arr[index2] = 1;
            return 1; //return true- the numbers found
        }
    }
}

//Function 3 Comparator function for use in qsort
int comparator(const void *p, const void *q)
{
    // Get the values at given addresses
    int l = *(const int *)p;
    int r = *(const int *)q;
    return l - r;
}

//Function 4 -Binary Searh
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
