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
int a[100005],b[100005];
int main()
{
	long long sum=0;
	int n,m,k,x,t,s,p;
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,n){
		scanf("%d",&x);
		b[x]=i;
		a[i]=x;
	}
	F(i,1,m){
		scanf("%d",&x);
		sum=sum+(b[x]+k-1)/k;
		if(b[x]!=1){
		s=b[x];
		t=a[s-1];p=b[x];b[x]=b[t];b[t]=p;a[s]=t;a[s-1]=x;	
		}
	}
	printf("%lld",sum);
	return 0;
}