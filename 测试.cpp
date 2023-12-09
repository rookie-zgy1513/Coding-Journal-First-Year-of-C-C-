#include<stdio.h>
int main()
{int N,K,aver,delta,c;
    int x[100];
	int n;
	int SUM,a,sum;
	SUM=a=sum=0;
	int h,i,j,k;
	h=j=i=k=1;
	int b=0;
	scanf("%d%d",&N,&K);
	while(i<=N){
		scanf("%d",&x[i]);
		sum=sum+x[i];
		i++;
	}
	if((int)(sum)%N==0.0)
		aver=(int)sum/N;
	else
	aver=(int)sum/N+1;

	
	while(j<=N){
		n=(x[j]-aver)*(x[j]-aver);
		a=a+n;
		j++;
		}
		delta=(int)a/N;
		
		while(k<=N){
			b=b + (x[k]>aver);
			k++;
			
	}
		
		while(h<=K){
			SUM=SUM+x[h];
			h++;
		}
		if((int)(SUM)%K==0)
		c=(int)SUM/K;
	else
	c=(int)SUM/K+1;
	printf("%d %d %d %d",aver,delta,b,c);
	return 0;
}
	