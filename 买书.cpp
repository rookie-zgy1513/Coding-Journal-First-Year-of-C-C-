#include<stdio.h>
int main()
{
	int n,fr;
	int m=0;
	double a,b;
	double sum=0.0;
	
while (scanf("%lf", &a) != EOF) {
	sum=sum+a;
	n=(int)(a)/10;
	m=m+n;
}
	b=(double)sum-10*m;
	printf("%d %.2lf",10*m,b);
	return 0;
}