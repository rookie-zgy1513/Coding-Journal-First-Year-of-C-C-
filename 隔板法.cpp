#include<stdio.h>
int n,k;
int getFac(int n)
{   int i;
    long long ans=1;
 for(i=1;i<=n;i++)
 {
 ans*=i; 
 }
 return ans;
}
void f(int x)
{
	
	int a;
	if(x==1)
	printf("1\n");
	else{
		printf(" ");
		for(a=1;a<x;a++){
			printf("%d",a);
			f(x-a);
		}
		printf("\n");
	}
}
int main()
{
	int i;
	long long way;
	scanf("%d%d",&n,&k);
	f(n-k+1);
	printf("%lld",getFac(n-1)/getFac(n-k));
	return 0;
}