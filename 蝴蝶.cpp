#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int a[1010]={0};
int main()
{
	int n,d,i,m;
	long long max=0,sum=0;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-d+1;i++){
		sum=0;
		for(m=0;m<d;m++){
			sum=sum+a[i+m];
		}
		if(sum>max)
		max=sum;
	}
	printf("%lld",max);
	return 0;
}