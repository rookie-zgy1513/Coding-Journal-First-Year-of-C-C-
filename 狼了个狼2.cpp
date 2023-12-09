#include<stdio.h>
int m[1000001];
int main()
{
	int n,M,min=1000001,max=0,i,re=0,s=0,op=0,sum=0;
	scanf("%d%d",&n,&M);
	for(i=1;i<=n;i++){
		scanf("%d",&m[i]);
		if(m[i]<min)
		min=m[i];
		if(m[i]>max)
		max=m[i];
	}
	while(min!=max){
		re=0;
		s=0;
		while(re<=M&&max>min-2){
		    re=0;
			for(i=1;i<=n;i++){
			if(m[i]>=max){
				s=m[i]-max;	
					}	
			else 
			s=0;
			re=re+s;}
	      max--;
	    }
		max=max+2;
		for(i=1;i<=n;i++){
			if(m[i]>=max){
				m[i]=max;
			}
		}
		op++;
	}
	printf("%d %d",min,op);
	return 0;
}