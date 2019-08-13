// Queston number 4

#include<stdio.h>

int main() {
int i,a,b;
printf("Enter the number of lines:");
scanf("%d",&i);
int j=i*2-2;
//iteration for line number
for (int a=0;a<i;a++){
      //iteration for printing the line
      for(b=0; b<j;b++){
          if(b==a) printf("*");
          else printf(" ");
          }
    printf("*\n");
    j--;
}}
