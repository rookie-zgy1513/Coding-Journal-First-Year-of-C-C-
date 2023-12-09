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
	return *(int*)c-*(int*)d;
}
int a[110];
int b[110];
int main()
{
	int cnt=0,max=-1;
	int n;
	scanf("%d",&n);
	F(i,0,n-1)
	scanf("%d",&a[i]);
	F(i,0,n-1)
	scanf("%d",&b[i]);
	qsort(a,n,sizeof(int),cmp);
	qsort(b,n,sizeof(int),cmp);
	F(i,1,n){
		cnt=0;
		F(j,1,i){
			if(a[n-j]>b[i-j])
			cnt++;
		}
		if(cnt>max)
		max=cnt;
	}
	printf("%d",max);
	return 0;
}