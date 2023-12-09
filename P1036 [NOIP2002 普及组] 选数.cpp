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
int a[110],b[110];long long count=0;
int n,m;
int isprime(long long a){
    for(int i = 2;i * i <= a; i++)
        if(a % i == 0)
            return 0;
    return 1;
}
void process(long long d,int e,int c){
	if(e==m){
		if(isprime(d))
		count++;
		return ;
	}
	F(i,c,n){
		if(b[i]!=0)continue;
		b[i]=1;
		process(d+a[i],e+1,i+1);
		b[i]=0;
	}
}
int main()
{
	
	scanf("%d%d",&n,&m);
	F(i,1,n)
	scanf("%d",&a[i]);
	process(0,0,1);
	printf("%lld",count);
	return 0;
}
