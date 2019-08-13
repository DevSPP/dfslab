//Question no 6

#include <stdio.h>

int main(){
unsigned int n,m,k;
printf("Enter the n:");
scanf("%u", &n);

//a
if ((n&1)==1){m=1;printf("odd\n");} // odd
else { m=0;printf("even\n");} // even
//b
if (((n>>2)<<2)-n==0){ m=1; printf("Divisible by 4\n");}
else {m=0; printf("Not divisible by 4\n");}
//c
int b=n<<1; printf("%u\n",b);
//d
printf("Enter K to shift: ");
scanf("%u",&k);
int a=n<<k; b=n>>(32-k);
printf("Left rotational shift: %u\n",a|b);
//e
a=n>>k; b=n<<(32-k);
printf("Right rotation shift: %u\n",a|b);

}
