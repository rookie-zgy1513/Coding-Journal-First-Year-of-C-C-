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
int a[200];
int main()
{
	int cnt=0,m=2;
	a[1]=5;
	printf("%d ",a[1]);
	F(i,6,370)
	{
		if(i%7==3)continue;
		else{
			if(cnt==3){
				a[m]=(i%7);
				if(a[m]==0)
				a[m]=7;
				printf("%d ",a[m]);
				cnt=0;
				m++;
			}
			else
			cnt++;
		}
	}
	F(i,1,m){
		printf("%d ",a[m]);
	}
	return 0;
	
	
	
	
}