#include<stdio.h>
int main()
{
	double a,b,c,d,h;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	h = (double)a*b*(1+c)*d+(1-d)*a*b;
	printf("%.4lf",h);
	return 0;

}