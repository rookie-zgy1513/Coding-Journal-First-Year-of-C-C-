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
int a[110];
int main()
{
	int n,l,r;
	long long max=-1,sum=0,ans=0;
	scanf("%d",&n);
	F(i,1,n)
	scanf("%d",&a[i]);
	F(i,1,n-1){
		sum=0;
		ans=a[i];
		F(j,i+1,n){
			ans=a[i];
			F(t,i,j-1){
				ans=ans^a[t+1];
			}
			if(ans>max){
			max=ans;l=i;r=j;	
			}
		}
	}
	F(i,1,n){
		if(a[i]==max){
			if(i<=l){
				max=a[i];
				l=i;r=i;
			}
		}
		else if(a[i]>max){
			max=a[i];
			l=i;r=i;
		}
	}
	printf("%d %d %lld",l,r,max);
	return 0;
}