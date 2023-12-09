#include<stdio.h>
int main()
{
	int t,n,m,x,i,j,use[5050]={0};
	scanf("%d",&t);
	while(t--){
		use[5050]={0};
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			use[x]++;
		}
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			scanf("%d",&x);
			use[x]++;
		}
		for(i=1;i<=5000;i++){
			if(use[i]==1)
			printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}