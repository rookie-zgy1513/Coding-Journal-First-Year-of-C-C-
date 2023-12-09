#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	long long int ans;
	while(scanf("%d",&a)!=EOF){
	if(a==0){
		ans=3;
	}
	else if(a==-1){
		ans=2;
	}
	else
	ans=abs(a)-1;
	printf("%lld\n",ans);
	}
    return 0;
}