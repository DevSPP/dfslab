#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int shift(int a[],int len, int loc);
void out(int *a, int tc, int c, int m);

int main()
{ //Taking the input from user
  int N; //number of test cases
  scanf("%d\n",&N);
  int l=0;
  char temp;
  int input[3]={0};
  int *ptr;
  int *mem;
  int tc,c,m;

  ptr=input;
  mem=(int*)malloc(sizeof(int));

  for(int n=0;n<N;n++)
    {   l=0;
        temp='a';
        while((temp)!='\n')
              {
                scanf("%d%c",ptr+l,&temp );
                l++;
              }
          tc=input[0],c=input[1]-1; //c=c-1
          m=input[2];
          mem=(int*)realloc(mem,sizeof(int)*tc);
          for(int j=0; j<tc;j++)
            mem[j]=j+1;
          out(mem,tc,c,m);
          free(mem);
    }
  return 0;
}
//---------------Function Definitions--------------------------

int shift(int a[],int len,int loc)
      { int b=a[loc];
        for(int i=loc;i<len;i++)
            a[i]=a[i+1];
        return b;
      }

void out(int *a,int tc, int c, int m)
      {
          while(tc>1)
          {
            c=(c+m-1)%(tc);
            tc--;
            printf("%d ",shift(a,tc,c));
          }
          printf("%d\n",a[0]);
      }
