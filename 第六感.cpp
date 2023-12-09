#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x[100],y[100],sum=0,a[100],i=1;
	scanf("%d%d%d%d%d",&x[1],&x[2],&x[3],&x[4],&x[5]);
    scanf("%d%d%d%d%d",&y[1],&y[2],&y[3],&y[4],&y[5]);
	while(i<=5){
		if(abs(x[i]-y[i])<100){
			a[i]=3;
		}
		else if(abs(x[i]-y[i])==100){
			a[i]=1;
		}
		else if(abs(x[i]-y[i])>100){
			a[i]=-1;
		}
		sum = sum +a[i];
		i++;
	}
	printf("%d",sum);
	return 0;
}