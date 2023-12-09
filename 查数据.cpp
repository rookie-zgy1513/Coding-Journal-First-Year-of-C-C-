#include<stdio.h>
#include<math.h>
long long N=pow(2,31)-1;
int v[N]={0};
int main()
{
	int n,op,id,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&id);
			scanf("%d",&v[id]);
		}
		else if(op==2){
			scanf("%d",&id);
			if(v[id]!=0)
			printf(" %d",v[id]);
			else 
			printf(" Not Found!");
		}
		else if(op==3){
			scanf("%d",&id);
			v[id]=0;
		}
		printf("\n");
	}
	return 0;
}