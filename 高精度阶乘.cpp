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
int main()
{
	int n,m,s,i,x,a;
	double sum=0.0;
	while(scanf("%d",&n)!=EOF){
		sum=0.0;
		for(i=1;i<=n;i++){
			sum=sum+log10(i);
		}
		m=(int)(sum-0)+1;
		x=n/5;
		a=pow(10,x);
		s=(n/a)%10;
		printf("%d %d\n",m,s);
	}	
	return 0;
}