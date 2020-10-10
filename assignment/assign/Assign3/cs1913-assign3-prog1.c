/*-----------------------------------
Name : SUBRAT PRASAD PANDA
Roll number : CS1913
Date : 01/11/2019
Program description : ASSIGNMENT 3, Question 1- Arranging Elements using min swap
Acknowledgements : NIL
------------------------------------*/
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define err_msg(x) \
    {              \
        perror(x); \
        exit(0);   \
    }

#define err_msg(x) \
    {              \
        perror(x); \
        exit(0);   \
    }

#define swap_inReverse                                   \
    swap = index_arr[temp_index1];                       \
    index_arr[temp_index1] = index_arr[temp_index1 - i]; \
    index_arr[temp_index1 - i] = swap;                   \
    break;

#define swap_inForward                                   \
    swap = index_arr[temp_index1];                       \
    index_arr[temp_index1] = index_arr[temp_index1 + i]; \
    index_arr[temp_index1 + i] = swap;                   \
    break;

int compare(char *names[], int index1, int index2) //Function to compare strings given the location of indices
{
    if (!strcmp(names[index1], names[index2]))
        return 1; //Match sFound
    else
        return 0; //Match not found
}
/*=======================LOGIC======================
1. Create an Array to store the index of *argv[] (strings)>>>> index_arr[]
2. The variables in the index_arr are swapped according to comparator function
3. Swapping is based on two traversal, forward and backward.
    During traversal optimal element is placed between two similar adjacent element
4. The result is printed accorting to the index store in index_arr
eg:
a)input stored in *argv[]>> ram ram sita
b)creation of index_arr>> 1 2 3
c)intermediate result using using traversal>> 1 3 2
d) Final result after resolving mapped strings>> ram sita ram
======================================================*/
int main(int argc, char *argv[])
{

    if (argc == 1)
        err_msg("no inputs");
    int len = argc - 1;
    int index_arr[len]; //to store the index of strings which will be manipulated instead of string

    for (int i = 1; i < argc; i++)
        index_arr[i - 1] = i; // assignment of index of argv pointers

    //=========================1. Traversing in Forward direction============================
    int temp_index1 = 1;
    int swap;
    while (temp_index1 < len)
    {
        if (compare(argv, index_arr[temp_index1 - 1], index_arr[temp_index1])) // When consecutive string matches
        {
            int i;
            for (i = 1; temp_index1 + i < len; i++)
            {
                if (!compare(argv, index_arr[temp_index1], index_arr[temp_index1 + i])) //no matching found in string
                {
                    //to handle special case of nearest adjecent neighbour
                    if ((i == 1) && (temp_index1 + 2 >= len ||
                                     !compare(argv, index_arr[temp_index1], index_arr[temp_index1 + 2])))
                    {
                        swap_inForward //swap variable
                    }
                    //other cases
                    else if ((!compare(argv, index_arr[temp_index1], index_arr[temp_index1 + i - 1])) &&
                             (temp_index1 + i + 1 >= len ||
                              !compare(argv, index_arr[temp_index1], index_arr[temp_index1 + i + 1])))
                    {
                        swap_inForward
                    }
                }
            }
        }
        temp_index1++; //keep checking for optimal element
    }

    //==========================2. Traversing in reverse direction===========================
    temp_index1 = len - 2;
    while (temp_index1 >= 0)
    {
        if (compare(argv, index_arr[temp_index1 + 1], index_arr[temp_index1])) // When consecutive string matches
        {
            int i;
            for (i = 1; (temp_index1 - i) >= 0; i++)
            {
                if (!compare(argv, index_arr[temp_index1], index_arr[temp_index1 - i])) //no matching in string
                {
                    //to handle special case of adjecent neighbour
                    if ((i == 1) && (temp_index1 - 2 <= 0 || !compare(argv, index_arr[temp_index1], index_arr[temp_index1 - 2])))
                    {
                        swap_inReverse;
                    }
                    else if ((!compare(argv, index_arr[temp_index1], index_arr[temp_index1 - i + 1])) &&
                             (temp_index1 - i - 1 <= 0 || !compare(argv, index_arr[temp_index1], index_arr[temp_index1 - i - 1])))
                    {
                        swap_inReverse;
                    }
                }
            }
        }
        temp_index1--;
    }
    //==========================3. Printing results=========================================
    for (int i = 0; i < len; i++)
        printf("%s ", argv[index_arr[i]]); //resolving the mapped index result to actual string
    printf("\n");
}