#include<stdio.h>
#include<math.h>
#define f(x) exp(-sqrt(x/10))/log(x/10)
int main()
{
	double x,y;
	double r=30.0,l=10.0;
	scanf("%lf",&y);
	while(fabs(r-l)>1e-6){
		
		if(f((l+r)/2)>y){
			l=(r+l)/2;
		}
		else if(f((l+r)/2)<y){
			r=(r+l)/2;
		}
	}
	x=r;
	printf("%.3lf",x);
	return 0;
}