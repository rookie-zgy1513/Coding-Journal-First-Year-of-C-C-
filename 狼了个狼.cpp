#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,i=1,b,t,c,flag;
	while(scanf("%d",&n)!=EOF){
		t=0;
		a=1;
		while(t!=n*a){
		t=n;
		while(a<=t){
		
		n=n/a;
		c=n;
		b=sqrt(n);
		for(flag=2;flag<=b;flag++){
			if(n==flag*flag){n=flag*a;i++;}break;
			}
	     if(c!=n)break;
	     a++;
			}
		}
		
		
		printf("%d %d",n,i);
		
	}
	return 0;
}