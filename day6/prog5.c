/*-----------------------------------
Name: SUBRAT PRASAD PANDA
Roll number: CS1913
Date: 13/08/2019
Program description: Enumeration of Cantor's Array
Acknowledgements: **
------------------------------------*/

#include <stdio.h>
#include <math.h>

int main()
{
  int N, i, j, sum = 0, n, d;
  scanf("%d", &N);
  n = sqrt(2 * N);
  sum = ((n) * (n + 1)) / 2;
  n = (N > sum) ? n + 1 : n;
  sum = ((n) * (n + 1)) / 2;
  d = (N > sum) ? N - sum : sum - N;
  if ((n & 1) == 0) //even
    i = (n - d), j = (d + 1);
  else //odd
    i = (d + 1), j = (n - d);
  printf("%d/%d\n", i, j);
}
