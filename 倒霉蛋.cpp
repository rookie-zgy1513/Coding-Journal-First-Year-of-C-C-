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
#define eps 1e-6
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int a[3000010][2]={0};
int cmp(const void*c,const void*d){
	return ((int*)c)[1]-((int*)d)[1];
}
int main()
{
	int n,m;
	scanf("%d",&n);
	F(i,0,3*n){
		read(a[i][0]);
		a[i][1]++;
	}
	m=3*n+1;
	qsort(a,m,2*sizeof(int),cmp);
	printf("%d",a[0][0]);
	return 0;
}