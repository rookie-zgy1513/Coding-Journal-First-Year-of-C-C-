#include<stdio.h>
int a[102]={0},b[102]={0};
int k;
int J(int n);
int main()
{
	int t,n,i;
	scanf("%d%d",&k,&t);
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<k;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		printf("%d\n",J(n));
	}
	return 0;
}

int J(int n)
{
	int ans;
	if(n<k)
	ans=a[n%k];
	else
	ans=k*J(n/k)+b[n%k];
	return ans;	
}