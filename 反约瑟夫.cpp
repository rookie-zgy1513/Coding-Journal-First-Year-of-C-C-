#include<stdio.h>
int n,m,k,number=1,i,count=1,sum=0;
int a[1005]={0},b[1005]={0};
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1){
		for(i=1;i<=n;i++){
			printf("%d ",i);
		}
	}
	else 
	{
		i=1;
		while(sum<n){
			if(number>n)
			number-=n;
			if(b[number]==0){
			if(count%m!=0){
				count++;
			}
			else{
			count=1;
			a[number]=i;
			i++;
			sum++;
			b[number]++;
			}
			number++;
		}
		else 
		number++;
	}
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
	}
	return 0;
}