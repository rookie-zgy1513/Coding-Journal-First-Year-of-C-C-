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
int b[100005];
int main()
{
	char c;
	int n,t,m,p;
	int max=0,min=100005;
	scanf("%d",&n);
	F(i,1,n){
		while(1){
			scanf("%d",&t);
			b[t]++;
			if(b[t]==2)
			m=t;
			if(t>max)
			max=t;
			if(t<min)
			min=t;
			c=getchar();
			if(c=='\n')break;
		}
	}
	F(i,min,max){
		if(b[i]==0){
			p=i;
		}break;
	}
	printf("%d %d",p,m);
	return 0;
}