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
#define eps 1e-6
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int main()
{
	int t,n,m;
	long long T;
	scanf("%d",&t);
	F(i,1,t){
		scanf("%d%d",&n,&m);
		if(m==1&&n>1)
		T=-1;
		else if(m==n)
		T=1;
		else{
		T=(n-m+m-1-1)/(m-1)*2+1;	
		}
		printf("%lld\n",T);
	}
	return 0;
}