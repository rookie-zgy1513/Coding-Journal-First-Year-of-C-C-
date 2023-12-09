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
int gys(int a,int b)
{
    int t;
    while (b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int main()
{
	int m,n;
	long long i=3;
	long long sum=0;
	long long first,second,temp,a;
	scanf("%d%d",&n,&m);
	first=n;second=m;
	sum=first+second;
	temp=gys(n,m)+MIN(n,m);
	while(temp<20000){
		a=gys(second,temp)+MIN(second,temp);
		second=temp;temp=a;
		i++;
	}
	printf("%lld",i);
	return 0;	
}