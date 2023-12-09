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
long long a[1005];
long long dp[1005];
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	F(i,1,n)
	scanf("%d",&a[i]);
	F(i,1,n){
		dp[i]=1;
	}
	F(i,1,n)
	F(j,1,i-1){
		if(a[i]>=a[j])
		dp[i]=MAX(dp[j]+1,dp[i]);
	}
	F(i,1,n)
	ans=MAX(ans,dp[i]);
	printf("%d",ans);
	return 0;
}