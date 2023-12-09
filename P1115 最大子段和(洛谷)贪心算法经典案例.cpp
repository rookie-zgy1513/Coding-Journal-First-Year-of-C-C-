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
int a[200005],b[200005];
int main()
{
	long long ans;
	int n;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d",&a[i]);
	}
	ans=a[1];
	b[1]=a[1];
	F(i,2,n){
		b[i]=MAX(a[i],b[i-1]+a[i]);
		ans=MAX(ans,b[i]);
	}
	printf("%lld",ans);
	return 0;
}