#include<stdio.h>
int f[10001]={0};
int main()
{
	int i,n;
	long long int b;
	f[1]=1,f[2]=1,f[3]=2,f[4]=3;
	for(i=5;i<=10000;i++){
		f[i]=f[i-1]%(1000000007)+f[i-4]%(1000000007);
	}
	scanf("%d",&n);
	b=f[n]%(1000000007);
	printf("%lld",b);
	return 0;
}