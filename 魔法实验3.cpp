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
long long cnt,flag,a[100100];
int main()
{
	int n,f,w,m,p,j,top,max=0;
	scanf("%d%d%d",&n,&f,&w);
	if(f!=0){
		F(i,1,f){
			scanf("%d",&m);
			a[m]=1;
			if(m>max)
			max=m;
		}
	}
	if(w!=0){
		F(i,1,w){
			scanf("%d",&p);
			a[p]=-1;
			if(p>max)
			max=p;
		}
	}
	if(f==0&&w==0)
	cnt=0;
	else{
		for(int i=max-1;i>=1;i--){
		if(a[i]==0){
			a[i]=-a[i+1];
		}
		else continue;
	}
	F(i,2,max){
		if(a[i]==a[i-1])
		cnt++;
	}
}
	printf("%lld",cnt);
	return 0;
}