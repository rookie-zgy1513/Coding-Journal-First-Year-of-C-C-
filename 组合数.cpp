/*#include<stdio.h>
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
unsigned long long arr[101][101]= {0};
unsigned long long combine(int n,int m)
{
	if(arr[n][m]==0)
 {
 if(m==0||m==n) return arr[n][m]=1;
 else return arr[n][m]=combine(n-1,m-1)+combine(n-1,m);
 }
 else return arr[n][m];
}
int main()
{
	int a,n,m;
	long long Ans;
	scanf("%d",&a);
	F(i,1,a)
	{
		scanf("%d%d",&n,&m);
		if(n<m){
		printf("You're kidding me!\n");
		continue;
		}
		printf("%llu\n",combine(n,m));
		
	}
	return 0;
}*/
/*#include<stdio.h>
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
unsigned long long a[110][110];
int main()
{
	int n,m,b;
	scanf("%d",&b);
	a[0][0]=1;a[1][0]=1;a[1][1]=1;
	F(i,2,101){
		a[i][0]=1;a[i][i]=1;
		F(j,1,i-1){
		a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
		
	}
	F(s,1,b){
		scanf("%d%d",&n,&m);
		if(n<m)
		printf("You're kidding me!\n");
		else
		printf("%llu\n",a[n][m]);
	}
	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#define F(i,l,r) for(int i=(l);i<=(r);i++)
unsigned long long a[11000][11000];
int main(int argc, char *argv[])
{
  long long count=1;
  int n;
  a[0][0]=1;a[1][0]=1;a[1][1]=1;
	F(i,2,10100){
		a[i][0]=1;a[i][i]=1;
		F(j,1,i-1){
		a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
		
	}
  scanf("%d",&n);
		F(i,0,10100)
    F(j,0,i){
      if(a[i][j]==n){printf("%lld",count);return 0;
	  }
      count++;
    }

  
  return 0;
}