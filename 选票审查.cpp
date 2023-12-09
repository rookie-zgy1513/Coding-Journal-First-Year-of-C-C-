#include<stdio.h>
int a[1010]={0},b[1010]={0};
int main()
{
	int k,t,i,n,m;
	scanf("%d %d %d",&k,&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=t;i++){
		scanf("%d",&m);
		printf("%d ",a[m]);
	}
	
	return 0;
}