/*--------------
Name: Mohamed Anas
Roll Number: 15
Date: 23.07.19
Program Description : Finding the standard deviation of a sequence of numbers
Acknowledgements:
--------------*/

#include<stdio.h>
#include<math.h>
int main(){
			int a,square = 0,sum=0,n=0;
			float mean = 0;
			scanf("%d",&a);
			
			if(a==0)return 0;
			do{
			n+=1;
			sum +=a;
			square+=a*a;
			scanf("%d",&a);
			}while(a!=0);
			
			mean=sum/n;
			
		//	printf("%f",sqrt((square-2*mean*sum+n*mean*mean)/n));
		
		printf("%f",sqrt(square/n-mean*mean));
			
}
