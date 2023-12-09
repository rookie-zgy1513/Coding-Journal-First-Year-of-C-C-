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
unsigned a,b,c,d,ans;
void swap(char *pa, char *pb)
{
char tem = *pa;
*pa = *pb;
*pb = tem; 
}
int main()
{
	scanf("%u%u",&a,&b);
	char*p1,*p2;
	p1=(char*)&a;p2=(char*)&b;
	swap(p1,p1+3);swap(p1+1,p1+2);
	swap(p2,p2+3);swap(p2+1,p2+2);
	ans=(a%10000)*(b%10000);
	ans=ans%10000;
	printf("%u",ans);
	return 0;
}