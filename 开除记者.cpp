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
int a[1050][1050];
int main()
{
	int n,m;
	
	while(scanf("%d",&n)!=EOF){
		m=(1<<n);
		F(i,1,m){
			a[m+1][i]=0;
		}
		F(i,1,m){
			a[1][i]=0;
		}
		a[1][m]=1;
		F(i,2,m)
		F(j,1,m)
		a[i][j]=a[i-1][j]^a[i-1][j+1];
		F(i,1,m){
		F(j,1,m){
			printf("%d ",a[i][j]);
		}
		printf("\n");
		}
		printf("\n");
	}
	return 0;
}