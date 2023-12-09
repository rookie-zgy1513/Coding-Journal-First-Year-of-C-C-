#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d%d",&a,&b);
	c=a & b;
	d=a | b;
	e=a ^ b;
	printf("%d %d %d",c,d,e);
	return 0;
}