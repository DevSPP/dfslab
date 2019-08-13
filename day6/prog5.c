#include <stdio.h>

int main(){

  int N,n;
  scanf("%d",&N);
  int diff=N;
  for(n=1;diff>0;n++)
    {diff -= n;}

  n--;
  diff=(diff<0)?(diff+n):diff;
  printf("n:%d diff:%d\n",n, diff );
  int i,j; // i=row and j=col
  if(n%2==0)//even case
  {
    if (diff==0) {
      i=n;
      j=1;
    }
    if (diff==1) {
      i=n+diff-1;
      j=1;
    }
    else {
    j=diff;
    i= n-(diff-1);}
  }
  else //odd case
    {
      if (diff==0) {
        i=n;
        j=1;
      }
      if(diff==1){
        i=n+diff-1;
        j=1;
      }
      if(diff>1) {
      j=diff;
      i= n-(diff-1);}
    }
  printf("%d/%d\n",j,i);
}
