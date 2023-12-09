#include<stdio.h>
#include<math.h>
int main()
{
	int t,i=1,n,a,b=0,m,c;
	scanf("%d",&t);
	while(i<=t){
		scanf("%d",&n);
		m=n;b=0;
		if(n==1){
			a=3;
		}
		else if(n%2==1){
			a=1;
		}
		else if(n%2==0){
		while(n%2==0){
			n=n/2;
			b++;
		}
		c=pow(2,b);
		if(c==m)
		a=c+1;
		else
		a=c;	
	}
	printf("%d\n",a);
	i++;	
	}
	return 0;
}