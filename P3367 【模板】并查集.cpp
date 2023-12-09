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
/*话说江湖上散落着各式各样的大侠，有上千个之多。他们没有什么正当职业，整天背着剑在外面走来走去，碰到和自己不是一路人的，就免不了要打一架。但大侠们有一个优点就是讲义气，绝对不打自己的朋友。而且他们信奉“朋友的朋友就是我的朋友”，只要是能通过朋友关系串联起来的，不管拐了多少个弯，都认为是自己人。这样一来，江湖上就形成了一个一个的帮派，通过两两之间的朋友关系串联起来。而不在同一个帮派的人，无论如何都无法通过朋友关系连起来，于是就可以放心往死了打。*/
int f[10005];
int n,m;
int find(int a){
	if(a==f[a])//如果一个侠客的掌门就是它自己
	return f[a];
	else{
		f[a]=find(f[a]);
		return f[a];
	}//否则就接下去寻找，直到找到他的掌门为止
	
}/*我们在判断两位英雄是否师出同门的时候，要用到查找掌门的函数。*/
void join(int a,int b){
	if(find(a)!=find(b)){
		f[find(a)]=find(b);
	}
}
int main()
{
	int op,x,y;
	scanf("%d%d",&n,&m);
	F(i,0,10004)
	f[i]=i;
	while(m--){
		scanf("%d%d%d",&op,&x,&y);
		switch(op){
			case 1:
			join(x,y);break;
			case 2:
			if(find(x)==find(y))
			printf("Y\n");
			else
			printf("N\n");
			break;
		}
	}
	return 0;
}
