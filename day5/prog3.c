#include <stdio.h>

int G(int a){
  if(a==0) return 0;
  if(a==1) return 1;
  if (a==2) return 2;

  return (G(a-1)+G(a-2)+G(a-3));
}






int main(){
int i;
int n=25;

i=G(n);
printf("%d \n",i);
// program for iterative method
i=3;
int a[3]={0};
a[0]=0; a[1]=1; a[2]=2;
while(i<=n){
  a[i%3]=a[0]+a[1]+a[2];
  i++;
}

printf("%d\n",a[(n%3)] );




}
