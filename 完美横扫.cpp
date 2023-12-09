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
	double s;
	int n;
	int r,l,w;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d%d%d",&r,&l,&w);
		if(2*r<=l&&2*r<=w)  
		s=3.1415926*r*r+l*w-(l-2*r)*(w-2*r)+2*l*r+2*w*r;
		else 
		s=3.1415926*r*r+l*w+2*l*r+2*w*r;
		printf("%.2lf\n",s);
		
	}
	return 0;
}