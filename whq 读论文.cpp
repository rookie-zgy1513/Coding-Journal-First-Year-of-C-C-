#include<stdio.h>
int main()
{
	long long sum=0;
	int first=-1,last=1e6+7;
	int n,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(a>first){
		first=a;
		}
		if(a<last)
		last=a;
		sum=sum+a;
		
	}
	if(n<=2)
	printf("%%%%? That's imp0ssib1e");
	else
	printf("%lld",sum-first-last);
	return 0;
}
