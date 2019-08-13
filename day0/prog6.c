#include <stdio.h>

int main(){
int m,n;

//a
if ((n&1)==1) m=1;printf("odd\n"); // odd
else m=0; printf("even\n"); // even 

//b
if (((n>>2)<<2)-n==0) printf("div\n");
else printf("not\n");



}
