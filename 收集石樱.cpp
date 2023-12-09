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
int a[10010]={0};
int main()
{
	long long sum=0,SUM=0,max=0;
	int t,n,m;
	scanf("%d",&t);
	F(i,1,t){
		sum=0;
		scanf("%d%d",&n,&m);
		if(n<=m){
			F(j,1,n){	
			scanf("%d",&a[j]);
			sum=sum+a[j];
			}
		sum=sum+(m-1)*m/2-(m-n)*(m-n-1)/2;
		}
		else{
			F(j,1,n)
			scanf("%d",&a[j]);
			F(j,1,n-m+1){
				sum=0;
				F(s,0,m-1){
					sum=sum+a[j+s];
				}
				if(sum>max)
				max=sum;
			}
			sum=sum+m*(m-1)/2;
		}
		printf("%lld\n",sum);	
	}
	return 0;
}