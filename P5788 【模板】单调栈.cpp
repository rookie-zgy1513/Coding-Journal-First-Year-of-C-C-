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
struct data {
	int height;
	int order;
} stuff[3000005];
int f[3000005],a[3000005];
int main()
{
	int n,j;int m=1;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d",&a[i]);
	}
	f[n]=0;stuff[1].height=a[n];stuff[1].order=n;
	for(int i=n-1;i>=1;i--){
		for(j=m;j>=1;j--){
		 if(a[i]<stuff[j].height){
		 f[i]=stuff[j].order;
				stuff[j+1].height=a[i];
				stuff[j+1].order=i;
				m=j+1;
				break;
		 }
	}	
		if(j==0){
		f[i]=0;
			stuff[1].height=a[i];
			stuff[1].order=i;
			m=1;   
		}
	}		
	F(i,1,n)
	printf("%d ",f[i]);
	return 0;
}