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
long long f(int x);
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",f(n));
	}
	return 0;
}

long long f(int x){
	int a,b;
	if(abs(x)<=1)return 1;
	else{
		if(x>1)
	return f(x/2)+f(x/3);
	else if(x<-1){
		if(x%2==0)
		a=x/2;
		if(x%3==0)
		b=x/3;
		if(x%2!=0)
		a=x/2-1;
		if(x%3!=0)
		b=x/3-1;
		return f(a)+f(b);
	}
	
	}
}