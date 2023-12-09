#include<stdio.h>
int main()
{
	int t,i,m=1;
	int n[1001]={0};
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n[i]);
		
	}
	while(m<=t){
	     if(n[m]%2==1){
			printf("-1\n");
		}
		else if(n[m]%4==0){
			printf("%d %d %d\n",n[m]/2+1,n[m]/2+1,1);
		}
		else if(n[m]%4==2){
			printf("%d %d %d\n",n[m]/2-1,n[m]/2-1,1);
		}
	m++;	
	}
	return 0;
}