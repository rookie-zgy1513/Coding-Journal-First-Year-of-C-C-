#include<stdio.h>
#include<math.h>
int main()
{
	long long int N,sum;
	int b=1,a;
	scanf("%lld",&N);
	a=log2(N);
	sum=(N>>0)&1;
	while(b<=a){
		sum=sum+((N>>b)&1);
		b++;
	}
	printf("%lld",sum);
	
	return 0;
}