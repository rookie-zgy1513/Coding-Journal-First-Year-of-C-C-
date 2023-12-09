#include<stdio.h>
int main()
{
	int x,a,i;
	scanf("%d",&x);
	for(i=1;i<=7;i++){
		scanf("%d",&a);
		if(x==a)
		x=x+2;
	}
	printf("%d",x);
	return 0;
}