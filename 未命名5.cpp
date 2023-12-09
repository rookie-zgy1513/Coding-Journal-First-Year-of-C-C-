#include<stdio.h>
int main()
{
	long long n,sum=0;
	int i=1,k,a;
	scanf("%lld%d",&n,&k);
	for(i=1;i<=k;i++){
		sum=0;
		for(a=0;a<=63;a++){
			sum+=((n>>a)&1)*a;
		}
		n=sum;
	}
	printf("%lld",sum);
	return 0;
}