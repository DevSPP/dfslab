



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{ //Taking the input from user
  char *str; // Storing th einput string
  int f_array[100]={0}; // Array taken to store frequency
  int len=0; // To store length
  int count=0; //Count the number of cont. characters

  while(scanf("%m[^\n]",&str))
     {
          len=strlen(str);
          getchar();// To take away \n in each line
          for(int i=0; i<=len;i++)
            {
              if(str[i]>=65 && str[i]<=90 || str[i]>=97 && str[i]<=122 ) count++;
              else
                 {if (count!=0) f_array[count]=f_array[count]+1; //Increase the frequency counter
                  count=0;
                 }
            }
          free(str);
          len=0, count=0;
    }
    free(str); //Free the memory
//*******************************printing results to the output-------------------
    int f_max=0, w_len=0;
    for(int i=0;i<10;i++)
      if(f_array[i] > f_max) f_max=f_array[i], w_len=i; // To search for maximum frequency

    printf("%d %d\n",w_len,f_max);
}
