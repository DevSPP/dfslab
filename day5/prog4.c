#include <stdio.h>
// 2^n - 2

int f ( int n )
{int s = 0;
  while (n--) s =s+ 1 + f(n);
  return s;
}

int main(){
  printf("%d\n",f(3) );
}
