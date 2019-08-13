/*----------------
Name: Mohamed Anas
Roll Number: 15
Date: 23.07.19
Program Description: Given 3 co-ordinates find whether they form a isosceles, scalene or equilateral triangle
Acknowlegments:
-----------------*/
#include<stdio.h>
int main(){
					int i;
					int x,y,arr[3][2],len[3];
					
					/*Storing the vertices */
					for(i=0;i<3;i++){
									
									scanf("%d %d",&x,&y);
									arr[i][0]=x;arr[i][1]=y;
									
					
					
					}
					/* Calculating the lengths*/
					for (i = 0 ; i < 3; i++){
					
									len[i]= (arr[i][0]-arr[(i+1)%3][0])*(arr[i][0]-arr[(i+1)%3][0])+(arr[i][1]-arr[(i+1)%3][1])*(arr[i][1]-arr[(i+1)%3][1]);

					
			
					}
					// Comparing the lengths
					if(len[0]!=len[1]){
									if(len[1]!=len[2] && len[2]!=len[0]){printf("Scalene\n");return 0;}
									else printf("Isoceles\n");
					}
					else if(len[1]!=len[2]) printf("Isosceles\n");
					else printf("Equilateral\n");
					
					
					
				return 0;	
					
					
					
				
}
