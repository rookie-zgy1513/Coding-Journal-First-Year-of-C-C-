#include<stdio.h>
#include<math.h>
int main()
{
	double r,a,x,y;
	scanf("%lf%lf",&r,&a);
	x=r*cos(a);
	y=r*sin(a);
	printf("%.1lf %.1lf",x,y);
	return 0;
}