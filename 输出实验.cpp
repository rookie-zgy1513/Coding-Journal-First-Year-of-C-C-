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
char s[100];
int main()
{
	int n;
	double m;
	scanf("%d",&n);
	printf("%d %e %o %X %e %E\n",n,n,n,n,n,n);
	scanf("%lf",&m);
	printf("%.3lf %6.3lf %5lf \n",m,m,m);
	printf("%-5d %05d %-05d %5d\n",n,n,n,n);
	itoa(n,s,16);
	printf("%s",s);
	return 0;
}