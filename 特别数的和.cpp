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
	long long sum=0;
	scanf("%d",&n);
	F(i,1,n){
		sprintf(s,"%d",i);
		if((strchr(s,'2')!=NULL)||(strchr(s,'0')!=NULL)||(strchr(s,'1')!=NULL)||(strchr(s,'9')!=NULL))
		sum=sum+i;
	}
	printf("%lld",sum);
	return 0;
}