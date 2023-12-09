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
int a[4];
int main()
{
	long long cmp1,cmp2;
	long long i=1;
	int flag=0;
	int n;
	while(scanf("%d",&n)!=EOF){
		a[1]=a[2];
		a[2]=a[3];
		a[3]=n;
		if(i==3)
		cmp1=a[2]-a[1];
		if(i>2){
		if((a[2]-a[1])*(a[3]-a[2])<0)
		flag=1;
		if(cmp1*(a[3]-a[2])<0)
		flag=1;
		if(a[3]-a[2]!=0)
		cmp1=a[3]-a[2];
		}
		i++;
		}
	if(flag)
	printf("No");
	else
	printf("Beautiful");
	return 0;
}