#include<stdio.h>
#include<math.h>
int main()
{
	double w,f;
	int a,n,b;
	a=0;
	scanf("%lf%lf",&w,&f);
	while(f*pow(2,a)<w){
		++a;
	}
	n=a;
	printf("%d",n);
	return 0;
}