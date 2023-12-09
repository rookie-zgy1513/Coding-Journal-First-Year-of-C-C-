#include<stdio.h>
#include<math.h>
#define eps 1e-6
int main()
{
	double a,b;
	int c;
	scanf("%lf%lf",&a,&b);
	if(a+b>0)
	c=(int)a+b;
	else{
	c=(int)fabs(a+b)+1;
	c=0-c;
	}
	
	if(fabs(a+b-c)<eps)
	c=c;
	else
	c++;
	printf("%d",c);
	return 0;
}