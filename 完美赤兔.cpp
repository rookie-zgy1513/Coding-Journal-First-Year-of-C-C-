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
long long a[1050][1050];
int b[1050][1050];
int main()
{
	long long m,sum=0;
	int n,k,r,x,y;
	scanf("%d%lld%d",&n,&m,&k);
	r=1<<n;
	a[1][1]=m+2*60*(n-1);
	F(i,2,r/2)
	a[1][i]=a[1][i-1]-40;
	a[1][r/2+1]=a[1][r/2];
	F(i,r/2+2,r)
	a[1][i]=a[1][i-1]-40;
	F(i,2,r/2)
	F(j,1,r)
	a[i][j]=a[i-1][j]-20;
	F(i,1,r)
	a[r/2+1][i]=a[r/2][i];
	F(i,r/2+2,r)
	F(j,1,r)
	a[i][j]=a[i-1][j]-20;
	F(i,1,k)
	{
		scanf("%d%d",&x,&y);
		if(b[x][y]==0){
			sum=sum+a[x][y];
			b[x][y]=1;
		}
	}
	printf("%lld",sum);
	return 0;
}