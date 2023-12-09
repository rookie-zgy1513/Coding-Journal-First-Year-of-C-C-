#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int i=(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int main()
{
	const int N=10000007;
	int n,t,m;
	long long ans=1;
	scanf("%d",&t);
	F(i,1,t)
	{
		ans=1;
		scanf("%d",&n);
		if(n==1)
		ans=1;
		else{
			while(n!=1&&n!=0){
				ans=((ans%N)*(n%N))%N;
				n=n-2;	
			}
		}
		printf("%lld\n",ans);
		
		
		
	}
	return 0;
}