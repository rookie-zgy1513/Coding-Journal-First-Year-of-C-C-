#include<stdio.h>
#include<math.h>
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int y[100000001]={0};
int main()
{
	long long int n,a,i=2,m,sum,b,c,d=2,x;

	scanf("%lld",&n);
	b=sqrt(n);
	m=n;
		while(i<=b){
			if(n%i==0)
			y[i]=1;
			i++;
		}
		sum=1+m;
		while(d<=b){
			a=0;
			if(y[d]>0){
				if((n/d)%d!=0)
				a=d+n/d;
			}
			sum=sum+a;
			d++;
		}
	printf("%lld",sum);
	return 0;
}