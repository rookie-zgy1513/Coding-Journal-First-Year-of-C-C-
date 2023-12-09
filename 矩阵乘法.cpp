#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int azzi =(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-6
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int a[15][15]={0},b[15][15]={0},c[15][15][15]={0};
int main()
{
	int m,n,p,i,j,s;
	scanf("%d%d%d",&m,&p,&n);
	F(i,1,m)
		F(j,1,p)
		scanf("%d",&a[i][j]);
	F(i,1,m)
		F(j,1,p)
		scanf("%d",&b[i][j]);
	F(i,1,m)
		F(j,1,m)
		    F(k,1,p)
		 c[1][i][j]=c[1][i][j]+a[i][k]*b[i][k];
	F(s,1,n-1)
	    F(i,1,m)
	      F(j,1,m)
	        F(k,1,m)
	      c[s+1][i][j]=c[s+1][i][j]+c[s][i][k]*c[1][k][i];
	F(i,1,m){
	   F(j,1,m)
	  {
	  	printf("%d ",c[n][i][j]);
	  }
	  printf("\n");
	  
	}
	  return 0;
}