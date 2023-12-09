#include<stdio.h>
int main()
{
	int N,i,a,x[50],result,sum,sub[50];
	scanf("%d",&N);
	a=i=1;sum=0;
	while(i<=N){
		scanf("%d",&x[i]);
		result = x[i] & (~(1 << 2));   
        result = result | 1; 
		sub[i]=x[i]-result;
		i++;       
	}
	while(a<=N){
		sum = sum+sub[a];
		a++;
	}
	printf("%d",sum);
	return 0;
}