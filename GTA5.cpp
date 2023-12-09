#include<stdio.h>
#include<math.h>
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	if(fabs(a-b)<1e-8){
		printf("0");
	}
	else if(a>b){
		printf("1");
	}
	else if(a<b){
		printf("-1");
	}
	return 0;
}