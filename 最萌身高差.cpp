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
int a[110];
int main()
{
	int n;
	scanf("%d",&n);
	F(i,1,n)
	scanf("%d",&a[i]);
	F(i,1,n-1)
		F(j,i+1,n){
			if(fabs(a[i]-a[j])>10&&(a[i]%2)^(a[j]%2)==0)
			printf("%d %d\n",i,j);
		}
	return 0;
}