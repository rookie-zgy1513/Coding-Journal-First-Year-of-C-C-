#include<stdio.h>
int main()
{
	long long int n;
	long long sum=0;
	scanf("%lld",&n);
	if(!n)
	printf("0");
	else{
		while(n){
			sum=sum+(n%2);
			n=n/2;
		}
		printf("%lld",sum);
	}
	return 0;
}