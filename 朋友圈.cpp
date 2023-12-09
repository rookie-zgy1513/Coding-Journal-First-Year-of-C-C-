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
int a[1010][1010]={0},cnt[1010]={0};
int main()
{
	int n,m,x,y,i;
	char op;
	scanf("%d%d",&n,&m);
for(i=1;i<=m;i++){
		scanf(" %c",&op);
		switch(op){
			case ('!'):
				scanf("%d",&x);
				F(j,1,n){
					if(a[x][j]>0)
					cnt[j]++;
				}break;
			case('+'):
				scanf("%d%d",&x,&y);
				a[x][y]=1;a[y][x]=1;break;
			case('-'):
			scanf("%d%d",&x,&y);
			a[x][y]=0;a[y][x]=0;break;	
		}
			
	}
	F(i,1,n)
	{
		printf("%d ",cnt[i]);
	}
	return 0;
}