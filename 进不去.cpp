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
int main()
{
	char a,b,c;
	int s,e;
	while(scanf(" %c%d%c%d%c",&a,&s,&b,&e,&c)!=EOF){
		if(fabs(s-e)+1<=32)
		printf("%d\n",abs(s-e)+1);
		else 
		printf("Too Big!\n");
	}
	return 0;
}