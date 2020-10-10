/*-----------------------------------
Name: SUBRAT PRASAD PANDA
Roll number: CS1913
Date: 12/10/2019
Program description: ASSIGNMENT 2, QUESTION NUMBER OF 2, Crossover points between two strings
Acknowledgements: NIL 
------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *p1, *p2, *c1, *c2; // Parents and Children String

    float p = 0;        //probability of cross over
    int index[4] = {0}; // Storing the Crossover points of parents

    //---------------------------USER INPUT---------------
    scanf("%f", &p);
    getchar();             //eats away \n character
    scanf("%m[^\n]", &p1); //memory allocation in heap
    if (p1 == NULL)        // Taking fixed sized array could have saved this statement
        p1 = "";
    getchar(); //eats away \n character
    scanf("%m[^\n]", &p2);
    if (p2 == NULL)
        p2 = "";
    getchar(); //eats away \n character
    scanf("%m[^\n]", &c1);
    if (c1 == NULL)
        c1 = "";
    getchar(); //eats away \n character
    scanf("%m[^\n]", &c2);
    if (c2 == NULL)
        c2 = "";
    //--------------------------------------------------
    //finding length of strings
    int c2_len = strlen(c2);
    int p1_len = strlen(p1);
    int c1_len = strlen(c1);
    int p2_len = strlen(p2);
    //----------------------------------------1. Generating index of parent 1
    int ctr1 = 1, ctr2 = 1; //Condition entry and exit control
    if (0 == p)             // If popability is zero
    {
        if (!strcmp(p1, c1) && !strcmp(p2, c2))
            printf("FEASIBLE\n");
        else
            printf("INFEASIBLE\n");
    }
    else if (p > 0 && p <= 1) // if non zero probability
    {
        for (int i = 0; i < p1_len; i++)
        {
            if (p1[i] == c1[i] && ctr1)
                index[0]++;
            else
                ctr1 = 0; // get first unmatch

            if (p1[p1_len - 1 - i] == c2[c2_len - 1 - i] && ctr2)
                index[1]++;
            else
                ctr2 = 0;
        }
        //------------------------------------------2. Generating index of parent 2
        ctr1 = 1, ctr2 = 1; //resetting ctr
        for (int i = 0; i < p2_len; i++)
        {
            if (p2[i] == c2[i] && ctr1)
                index[2]++;
            else
                ctr1 = 0; // get first unmatch

            if (p2[p2_len - 1 - i] == c1[c1_len - 1 - i] && ctr2)
                index[3]++;
            else
                ctr2 = 0;
        }

        /*--------------------------------------------LOGIC----------------------------------------
    ==> Initially we found the matching index of parent with childrens above stored in index[]

    Check Conditions: 1. Find the sum of index equals with parents or not, simple case
                      2. If the sum is less that parents length then, INFEASIBLE
                      3. IF the sum is more, then possibility of multiple crossover points.
                      4. Print all possible combination by evaluating each cases.
        
    -------------------------------------------------------------------------------------------*/
        //3. Checking for validity
        if ((index[0] + index[1] == p1_len) && (index[2] + index[3] == p2_len))
            printf("%d %d\n", index[0], index[2]);
        else if ((index[0] + index[1] < p1_len) || (index[2] + index[3] < p2_len))
            printf("INFEASIBLE\n");
        else
        {                                                //========================================WORKING with MULTIPLE CROSSOVER Index=======================
            int p1_index = index[0] + index[1] - p1_len; // possible index range for cross over in p1
            int p2_index = index[2] + index[3] - p2_len; // possible index range for cross over in p2

            int exp_c1_len, exp_c2_len, ctr1 = 1; //Expected length of cheldrens due to multiple crossover points
            // Compare all possible index of crossoverpoints to check validity
            // Print all possible combinations
            for (int i = index[0]; i > index[0] - p1_index; i--)
            {
                for (int j = index[2]; j > index[2] - p2_index; j--)
                {
                    exp_c1_len = i + p2_len - j;
                    exp_c2_len = p1_len - i + j;
                    if (exp_c1_len == c1_len && exp_c2_len == c2_len)
                    {
                        printf("%d %d\n", i, j); // Print all possible combinations
                        ctr1 = 0;
                        break;
                    }
                }
            }
            if (ctr1)
                printf("INFEASIBLE\n");
        }
    }
    else
    {
        printf("Probability Value not in range\n");
    }
    //Free heap memory //checking condition of null string
    if (p1 != "")
        free(p1);
    if (p2 != "")
        free(p2);
    if (c1 != "")
        free(c1);
    if (c2 != "")
        free(c2);
}