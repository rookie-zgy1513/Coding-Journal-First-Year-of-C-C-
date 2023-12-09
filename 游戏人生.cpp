#include<stdio.h>
int main()
{
	int X1,X2,s1,X3,X4,s2,X5,X6,s3,x,i;
	scanf("%d%d%d",&X1,&X2,&s1);
	scanf("%d%d%d",&X3,&X4,&s2);
	scanf("%d%d%d",&X5,&X6,&s3);
	scanf("%d",&i);
	if(i<=X2 && i>=X1){
		x=s1;
		printf("%d",x);
	}
	if(i<=X4 && i>=X3){
		x=s2;
		printf("%d",x);
	}
	if(i<=X6 && i>=X5){
		x=s3;
		printf("%d",x);
	}
	if(i<X1 ||(i>X2 && i<X3)||(i>X4 && i<X5)||i>X6){
		printf("None");
	}
	return 0;
	
}