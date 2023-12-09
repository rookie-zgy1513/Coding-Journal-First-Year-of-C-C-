#include<stdio.h>
int main()
{
	int t,a,b,x,y,i,n,use[5005]={0};
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		use[5005]={0};
		scanf("%d",&a);
		for(n=1;n<=a;n++){
			scanf("%d",&x);
			use[x]++;
		}
		scanf("%d",&b);
		for(n=1;n<=b;n++){
			scanf("%d",&y);
			use[y]++;
		}
		for(n=1;n<=5000;n++){
			if(use[n]==1){
			printf("%d",n);
			printf(" ");
			}
			
		}
		printf("\n");
	}
	return 0;
}