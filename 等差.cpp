#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int main()
{
	int t,i,b,k,n;
	long long int sum;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d%d",&b,&k,&n);
		sum=(b+b-(n-1)*k)*n/2;
		printf("%lld\n",sum);
	}
	return 0;
	
	
	
	
	
}