/*-----------------------------------
Name: SUBRAT PRASAD PANDA
Roll number: CS1913
Date: 11/10/2019
Program description: ASSIGNMENT 2, QUESTION NUMBER OF 1, Optimization of Hypergeometric p-value
Acknowledgements: NIL 
------------------------------------*/

#include <stdio.h>
#include <sys/time.h>

#define GAP(start, end) ((end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000)

int main()
{
    long int n, N, e, E;
    long int var1, var2; //temporary variables
    float p_value = 1, next;
    struct timeval start_time, end_time;
    fscanf(stdin, "%ld%ld%ld%ld", &n, &N, &e, &E);
    //Time Starts from here
    gettimeofday(&start_time, NULL); //Program Timer starts here

    /* ===========================Logic========================
        1.For Hypergeometric distrbution:
                    P(X=i+1)        (e-i) * (N-i)
                    --------  =  -----------------------
                    P(X=i)          (i+1) * (E-e-N+i=1)
        
        2.Base Case: P(X=0) = (E-e) Choose N
                              ---------------
                                E Choose N
        
        3.Summation form 0 to n-1 instead of n to N so 
                    p_value = 1- p_value
       
       *4.Can be optimized further by comparing n and N-n+1
                    start program from backward base case
   ===========================================================*/
    //1. Calculation for base case
    if (E - e >= N)
    {
        for (long int i = 0; i < N; i++)
        {
            if (E - e > i)
                p_value = (p_value * (E - e - i)) / (E - i);
        }
    }
    else
    {
        var2 = N - E + e; // for the cases where E-e >N (eg 10 Choose 15)
        for (long int i = 0; i < N; i++)
        {
            if (i < var2)
                p_value = p_value * ((e - i) * (N - i)) / ((var2 - i) * (E - i));
            else
                p_value = (p_value * (N - i)) / (E - i);
        }
    }
    next = p_value; // base case assigned to next to calculate probability of next i
    var1 = E - e - N + 1;

    //2. Calculation of sum till P(X < n)
    for (long int i = 0; i < n - 1; i++)
    {
        if (var1 + i > 0 && e > i && N > i)
        {
            next = next * ((e - i) * (N - i)) / ((i + 1) * (var1 + i));
            p_value = p_value + next;
        }
    }

    //3. Subtraction from 1 to get desired result
    p_value = 1.0 - p_value;

    gettimeofday(&end_time, NULL);
    printf("p-value = %f (%d microseconds)", p_value, (int)GAP(start_time, end_time));
    return 0;
}
