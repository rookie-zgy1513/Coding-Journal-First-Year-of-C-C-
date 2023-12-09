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
long long ans[15][15][15];
long long m[15][15][15];
int main()
{
	int n,i,j,t;
	int a[15],b[15];
	scanf("%d",&n);
	F(i,1,n)
	scanf("%d%d",&a[i],&b[i]);
	for (int i = 0; i < a[1]; i++)
for (int j = 0; j < b[1]; j++)
scanf("%lld", &m[1][i][j]);
for (int i = 0; i < a[2]; i++)
for (int j = 0; j < b[2]; j++)
scanf("%lld", &m[2][i][j]);
for (int i = 0; i < a[1]; i++)
for (int j = 0; j < b[2]; j++)
for (int k = 0; k <a[2] ; k++)
ans[1][i][j] += m[1][i][k] * m[2][k][j];
for(t=2;t<=n-1;t++){
for (int i = 0; i < a[t+1]; i++)
for (int j = 0; j < b[t+1]; j++)
scanf("%lld", &m[t+1][i][j]);	
for (int i = 0; i < a[1]; i++)
for (int j = 0; j < b[t+1]; j++)
for (int k = 0; k <a[t+1] ; k++)
ans[t][i][j] += ans[t-1][i][k] * m[t+1][k][j];	
}

	for (int i = 0; i < a[1]; i++)
{
for (int j = 0; j < b[n]; j++)
printf("%lld ", ans[n - 1][i][j]);
printf("\n");
}
return 0;	
}