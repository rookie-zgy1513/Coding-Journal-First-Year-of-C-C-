#include<stdio.h>
int main()
{
	int n,i=1,x,t[10001]={0},use[10001]={0};
	scanf("%d",&n);
	while(i<=n){
		scanf("%d",&t[i]);
		for(x=2;x<=t[i];x++){
			if(t[i]%x!=0)continue;
			while(t[i]%x==0){
				t[i]/=x;
				use[i]++;
			}
		}
		i++;
	}
	i=1;
	while(i<=n){
		if(use[i]%2==1)
		printf("lose\n");
		else 
		printf("win\n");
		i++;
		}
		
	return 0;
}