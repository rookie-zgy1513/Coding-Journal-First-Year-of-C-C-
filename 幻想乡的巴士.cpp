#include<stdio.h>
int s[1010]={0};
int t[1010]={0};
int main()
{
	int n,T,i,min=1000000000,num,wait;
	scanf("%d%d",&n,&T);
	for(i=1;i<=n;i++){
		scanf("%d%d",&s[i],&t[i]);
	  	if((s[i]>=T&&s[i]>=min)||((((T-s[i]+t[i]-1)/t[i])*t[i]+s[i]>=min)&&s[i]<T))continue;
			min=s[i];
			num=i;
	}
     printf("%d",num);
	 return 0;	
}