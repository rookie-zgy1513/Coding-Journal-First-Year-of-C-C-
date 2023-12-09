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
int a[15],b[15],c[15];
int main()
{
	long long sum;
	int x,y,z;
	int n,t;
	scanf("%d%d",&n,&t);
	F(i,1,n)
	scanf("%d%d%d",&a[i],&b[i],&c[i]);
	F(i,1,t){
		scanf("%d%d%d",&x,&y,&z);
		sum=a[z]*(b[x]*c[y]-c[x]*b[y])-b[z]*(a[x]*c[y]-c[x]*a[y])+c[z]*(a[x]*b[y]-a[y]*b[x]);
		printf("%lld\n",sum);
	}	
	return 0;
}