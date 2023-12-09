#include<stdio.h>
#include<math.h>
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int main()
{
	double t;
	scanf("%lf",&t);
	if(t<37.0)
	printf("OK");
	else if(fabs(t-37.0<1e-6)||((t>37.0)&&(t<37.5)))
	printf("Warning");
	else if(t>37.5||fabs(t-37.5<1e-6))
	printf("Fever");
	return 0;
}