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
int a[40];
int main()
{
	long long ans=0;
	int k,n,m=0;
	scanf("%d%d",&k,&n);
	while(n){
		a[m]=(n%2);
		n=n/2;m++;
	}
	F(i,0,m){
		ans=ans+a[i]*(pow(k,i));
	}
	printf("%lld",ans);
	return 0;
}