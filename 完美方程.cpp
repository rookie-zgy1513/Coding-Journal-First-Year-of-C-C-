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
int main()
{
double a, b, c, r1, r2, dt;
while(scanf("%lf%lf%lf", &a, &b, &c)!=EOF){
dt = b * b - 4 * a * c;
if(fabs(a) < eps&&fabs(b) < eps&&fabs(c) < eps){
	printf("-1\n");
}
else if(fabs(a) < eps&&fabs(b) < eps&&fabs(c) >= eps)
printf("0\n");
else{
	if(fabs(a) < eps){
		if(c!=0)
		printf("1 %.2lf\n",(-c)/b);
		else
		printf("1 0.00\n");
	}
else if (fabs(dt) < eps)
printf("2 %.2lf %.2lf\n", -(b / (2 * a)),-(b / (2 * a)));
else if (dt > 0.0)
{
r1 = (-b + sqrt(dt)) / (2 * a);
r2 = (-b - sqrt(dt)) / (2 * a);
printf("2 %.2lf %.2lf\n",MIN(r1,r2),MAX(r1,r2) );
}
else
printf("0\n");
}
}
return 0;
}
