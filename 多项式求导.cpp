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
long long int a[100010],b[100010];
long long c[100010];
int main()
{
	 long long int n,i;
	scanf("%lld",&n);
	for(i=n;i>=1;i--){
		scanf("%lld %lld",&a[i],&b[i]);
		c[i]=a[i]*b[i];
	}
	for(i=n;i>=1;i--){
		if(c[i]!=0)
		printf("%lld %lld ",c[i],b[i]-1);
	}
	return 0;
}