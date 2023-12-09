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
int a[100005];
long long ans[100005];
int main()
{
	int n,k;
	const long long int N=1e9+7;
	scanf("%d%d",&n,&k);
	F(i,1,n)
	scanf("%d",&a[i]);
	ans[0]=1;
	F(i,1,n){
		for(int j=k;j>=0;j--)
		ans[j]=((ans[j]+ans[j-1]*a[i])%N);
	}
	printf("%lld",ans[k]);
	return 0;
}