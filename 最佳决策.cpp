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
int a[410][410];
int main()
{
	int m,n,x,y,s1[410]={0},s2[410]={0},max=-1,sum=0;
	scanf("%d%d",&m,&n);
	F(i,1,m){
		F(j,1,n){
			scanf("%d",&a[i][j]);
			s1[i]+=a[i][j];
		}
	}
	F(i,1,n){
		F(j,1,m){
			s2[i]+=a[j][i];
		}
	}
	F(i,1,m){
		F(j,1,n){
		sum=s1[i]+s2[j]-a[i][j];
		if(sum>max){
	max=sum;x=i;y=j;
		}
	  }
	}
	printf("%d %d %d",x,y,max);
	return 0;	
}