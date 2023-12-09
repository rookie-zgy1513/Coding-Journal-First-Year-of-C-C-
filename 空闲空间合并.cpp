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
typedef struct dis{
	int l;
	int r;
}Dis;
Dis district[110];
int cmp(const void*p1,const void*p2)
{
	struct dis *x=(struct dis*)p1;
	struct dis *y=(struct dis*)p2;
	if(x->l!=y->r)return x->l-y->l;	//先排起点 
	else return x->r-y->r;			//再排终点 
}
int main()
{
	int n;
	scanf("%d",&n);
	F(i,0,n-1){
		scanf("%d%d",&district[i].l,&district[i].r);
	}
	qsort(district,n,sizeof(Dis),cmp);
	F(i,0,n-1){
		F(j,0,n-1){
			if(district[i].r+1==district[j].l){
				district[i].r=district[j].r;
				district[j].l=-1;
			}
		}
	}
	qsort(district,n,sizeof(Dis),cmp);
	F(i,0,n-1){
		if(district[i].l!=-1)
		printf("%d %d\n",district[i].l,district[i].r);
	}
	return 0;
}