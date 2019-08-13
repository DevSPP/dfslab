#include<stdio.h>


int swap(int *A, int i, int k)
{
  int temp;
  temp=A[k];
  A[k]=A[i];
  A[i]=temp;
  return 0;
}

void  permute(int *A, int k, int n){
int i;

  if(k==n)
  {
    for(i = 0; i < n; i++)
    {printf("%d ", A[i]);
    }
    printf("\n");
    return;
  }


  for (i=k;i<n;i++)
  {
    swap(A, i, k);
    permute(A, (k+1),n);
    swap(A, k, i);
  }

  return;
}




int main(){
  int A[3]={1,2,3};
  permute(A,0,3);

}
