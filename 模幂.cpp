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
long long a,b,p,ans;
long long qpow(long long a, long long b, long long p)
{
	long long ans = 1;
	a = a % p;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}

int main()
{
scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld",qpow(a,b,p));
	return 0;
}
