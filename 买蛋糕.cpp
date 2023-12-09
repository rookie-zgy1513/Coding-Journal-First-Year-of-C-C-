#include<stdio.h>
int main()
{
	int n,m,o,p;
	int u,b,i;
	long long int a[100],sum[100];
	scanf("%d%d",&n,&m);
	i=1;
	while(i<=n){
		scanf("%lld",&a[i]);
		i++;
	}
	b=1;
	while(b<=m){
		scanf("%d%d",&o,&p);
		sum[b]=(long long int)a[o]+a[p];
		b++;
		
	}
	u=1;
	while(u<=m){
		printf("%lld\n",sum[u]);
		u++;
	}
	return 0;
}