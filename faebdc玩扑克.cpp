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
int a[1000005],b[1000005];
int main()
{
	int n,m=2;
	int cnt=0;
	a[2]=1;b[2]=1;
	scanf("%d",&n);
	F(i,2,n){
		while(cnt!=2){
			m++;
			if(m>n)
			m=m-n;
			if(b[m]==0)
			cnt++;
		}
		a[m]=i;b[m]=1;
		cnt=0;
	}
	F(i,1,n)
	printf("%d ",a[i]);
	return 0;
}