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
int cmp(const void*c,const void*d){
	if(((int*)c)[1]<((int*)d)[1])return -1;
	if(((int*)c)[1]>((int*)d)[1])return 1;
	if(((int*)c)[0]<((int*)d)[0])return -1;
	if(((int*)c)[0]>((int*)d)[0])return 1;
}
int a[1010][2];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	F(i,0,n-1){
		scanf("%d",&a[i][0]);
		a[i][1]=abs(a[i][0]-m);
	}
	qsort(a,n,2*sizeof(int),cmp);
	F(i,0,n-1){
		printf("%d\n",a[i][0]);
	}
	return 0;
}