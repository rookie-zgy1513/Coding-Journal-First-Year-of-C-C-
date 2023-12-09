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
long long int gys(long long int a,long long int b)
{
    long long int t;
    while (b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int main()
{
	int a,b,c,d,op;
	long long ans=0,ans1,ans2,ans3;
	while(scanf("%d/%d%d/%d",&a,&b,&c,&d)!=EOF){
		scanf("%d",&op);ans=0;
		if (op == 1)
 ans1 = a * d + b * c, ans2 = b * d;
 else if (op == 2)
 ans1 = a * d - b * c, ans2 = b * d;
 else if (op == 3)
 ans1 = a * c, ans2 = b * d;
 else
ans1 = a * d, ans2 = b * c;
if(ans1<0){
ans=1;ans1=-ans1;
}
if(ans)
printf("-");
if(ans1%ans2==0)
printf("%lld",ans1/ans2);
else
printf("%lld/%lld\n",ans1/gys(ans1,ans2),ans2/gys(ans1,ans2));

	}
	return 0;
}