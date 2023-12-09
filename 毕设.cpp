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
double f(double x) {
double ans = (3.1415926535-2*x)/(2*sin(x)*sin(x))-1/tan(x);
return ans;
}
int main()
{
	double y;
	double l=0.0,r=5000.0,m;
	scanf("%lf",&y);
	while(fabs(r-l)>eps){
	m=(l+r)/2;
	if(f(m)<y)
	r=m;
	else if(f(m)>y)
	l=m;
	}
	printf("%.6lf",m);
	return 0;
}