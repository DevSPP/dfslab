#include <stdio.h>

#define imp(x,y) (!x|y)
#define swap(x,y) {x=x+y; y=x-y;x=x-y;}
#define max(x,y) ((x>y)?x:y)
#define min(x,y) ((x<y)?x:y)
#define infiloop(a) {while(printf("%s",a));}
#define lbit(a) a&1

int main(){
int a= imp(0,1);
printf("%d\n", a);
int x=2,y=4;
swap(x,y);
printf("%d %d\n",x,y );
printf("%d\n", max(5,2));
printf("%d\n", min(6,7));
printf("%d\n",lbit(3) );
infiloop("asd");
}
