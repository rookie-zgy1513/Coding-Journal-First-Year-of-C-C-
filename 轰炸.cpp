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
long long int cnt[310][310];
int flag[310][310];
int main()
{
	int n,m,k,q,a,b;
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	F(i,1,k){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		F(j,x1,x2){
		F(t,y1,y2){
			cnt[j][t]++;
			flag[j][t]=i;
		}
		}
	}
	F(i,1,q){
		scanf("%d%d",&a,&b);
		if(cnt[a][b]==0)
		printf("N\n");
		else
		printf("Y %lld %d\n",cnt[a][b],flag[a][b]);
	}
	return 0;
}