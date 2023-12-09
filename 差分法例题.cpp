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
int a[1000005];
int main()
{
	int n,m;
	int l,r,s;
	scanf("%d%d",&n,&m);
	F(i,1,m){
		scanf("%d%d%d",&l,&r,&s);
		a[l]=a[l]+s;
		a[r+1]=a[r+1]-s;
	}
	F(i,1,n){
		a[i]=a[i]+a[i-1];
		printf("%d ",a[i]);
	}
	return 0;
}