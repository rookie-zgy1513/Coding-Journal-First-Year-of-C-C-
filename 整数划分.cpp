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
int divide(int m,int k);
int main()
{
	int t,n,sum;
	scanf("%d",&t);
	F(i,1,t)
	{
		scanf("%d",&n);
		sum=divide(n,n);
		printf("%d\n",sum);
	}
	return 0;
}
int divide(int m,int k)
{
	if(m==1||k==1)
	return 1;
    else if(k==m)
	return 1+divide(m,m-1);
	else if(m>k)
	return divide(m-k,k)+divide(m,k-1);
}