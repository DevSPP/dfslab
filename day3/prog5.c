#include<stdio.h>

int main(){
typedef struct{ int r; int i;} complex;
complex x, y;
printf("Enter x:");
scanf("%d %d", &x.r, &x.i);
printf("Enter y:");
scanf("%d %d", &y.r, &y.i);

//1
if ((x.i)+(y.i) !=0 && (x.r+y.r)=0) {printf("The sum is imaginary! \n");}
else {printf("The sum not imaginary! \n");}
//2
if ((x.i)-(y.i) !=0) {printf("The subtraction is imaginary! \n");}
else {printf("The subtraction not imaginary! \n");}
//3
if ((x.r)==(y.r) && (x.i)== (-1)*(y.i)  ) {printf("Yes, conjugates! \n");}
else {printf("No, not conjugates! \n");}
//4
if ((x.i)==0 && (y.i)==0  ) {printf("Both Real \n");}
else {printf("Both Not real! \n");}
}
