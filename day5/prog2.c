#include<stdio.h>

int c(int x,int y){
  if (x<y)
  printf("Error");
  if (x==y)
  return 1;
  if(y==0)
  return 1;

  return (c(x-1,y)+c(x-1,y-1));

}

int main(){
  printf("%d\n", c(4,2) );
}
