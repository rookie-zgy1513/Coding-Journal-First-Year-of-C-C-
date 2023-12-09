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
int a[70];
int main()
{
	int n,j=0,i;
	long long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==1){
		if(a[0]==0)
		a[0]=1;
		else
		a[0]=0;
		}
		if(i%2==0){
			if(i==2)
			a[1]=1;
			else{
				for(j=0;j<=65;j++){
					if(a[j]==1)break;
				}
				if(a[j+1]==0)
		a[j+1]=1;
		else if(a[j+1]==1)
		a[j+1]=0;
				
			}
		}
	}
	for(i=0;i<=64;i++){
		sum=sum+a[i]*(1<<i);
	}
	printf("%lld",sum);
}