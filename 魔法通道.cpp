#include<stdio.h>
int main()
{
	int n,s[1001],i,b,step=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	while(n>1){
		if(n<=10){
			for(b=1;b<n;b++){
				if(s[b]>=n-b)break;
			}
			n=b;
		}
		else
		{
			for(b=n-10;b<n;b++){
				if(s[b]>=n-b)break;
			}
			n=b;
			}
		step++;
	}
	printf("%d",step);
	return 0;
}