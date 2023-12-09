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
int a[10010];
int main()
{
	int n,m,l,max=0,j;
	long long sum=0,s;
	scanf("%d%d",&n,&m);
	F(i,1,n){
		scanf("%d",&a[i]);
		a[i]=a[i]%m;
		sum=sum+a[i];
	}
	s=sum;
	F(i,1,n){
		sum=sum-a[i-1];s=sum;
		for(j=n;j>=i;j--){
			s=s-a[j+1];
			if(s%m==0)break;
		}
		l=j-i+1;
		if(l>max)
		max=l;
		if(max>=n-i)break;
	}
	printf("%lld",max);
	return 0;
}