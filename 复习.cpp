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
int a[1010]={0};
int main()
{
	int m,n,l,r,flag=0,max=0,x;
	scanf("%d%d",&m,&n);
	F(i,1,m){
		scanf("%d%d",&l,&r);
		F(b,l,r){
		a[b]++;	
		}
	}
	F(i,1,n){
		if(a[i]==0)
		flag=1;
		if(a[i]>max){
			max=a[i];
			x=i;
		}
	}
	if(!flag)
	printf("Yes\n");
	else
	printf("No\n");
	printf("%d",x);
	return 0;
}