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
long long int a[210],b[210];
int main()
{
	int n,cnt=1,flag=0;
	scanf("%d",&n);
	F(i,1,n)
	{
		scanf("%lld",&a[i]);
		a[i]=a[i]/2;
		if(a[i]<=0&&b[i]==0){
		flag++;b[i]++;
		}
		
	}
	while(flag>0){
		flag=0;
		F(i,1,n){
			if(b[i]>0)continue;
			a[i]=a[i]/2;
		if(a[i]<=0){
		flag++;b[i]++;
		}
		
	}cnt++;
}
flag=0;
	F(i,1,n){
		
		if(a[i]>0)
		flag++;
	}
	if(flag)
	printf("%d\nSome number left...",cnt);
	else{
	printf("%d\n",cnt-1);
	printf("Clear!");
	}
	
	return 0;
}