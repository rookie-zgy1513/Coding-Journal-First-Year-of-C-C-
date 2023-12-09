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
struct s{
	int l,r,f;
}stu[100005];
void add(int a,int b,int c){
	if(c==1){
		stu[b].r=stu[a].r;
		stu[b].l=a;
		stu[a].r=b;
		stu[stu[b].r].l=b;	
	}
	else{
		stu[b].r=a;
		stu[b].l=stu[a].l;
		stu[a].l=b;
		stu[stu[b].l].r=b;
	}
}
int main()
{
	stu[0].r=0;stu[0].l=0;stu[0].f=0;
	add(0,1,1);
	int n,m,x,s,i;
	scanf("%d",&n);
	F(i,2,n){
		scanf("%d%d",&x,&s);
		add(x,i,s);
	}
	scanf("%d",&m);
	F(i,1,m){
		scanf("%d",&x);
		stu[x].f=1;
	}
	i=stu[0].r;
	while(i){
		if(stu[i].f==0)
		printf("%d ",i);
		i=stu[i].r;
	}
	return 0;
}