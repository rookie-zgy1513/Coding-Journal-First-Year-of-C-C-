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
typedef struct Node{
    int num;
    struct Node *child[3];
}Tree;
Tree airport_gate[5000];
typedef struct AirNode{
    int num;
    int flow;
}airport_ch,*checkptr;
airport_ch airport_check[5000];
int after[5000],gatenum;
void select(Tree* t){
	Tree* queue[5000];Tree*p;
	int f=0,r=0;
	queue[0]=t;
	while(f<=r){
		p=queue[f++];
		if(p->child[0]==NULL&&p->child[1]==NULL&&p->child[2]==NULL){
            after[gatenum++] = p->num;
        }
        if(p->child[0]!=NULL)
            queue[++r]=p->child[0];
        if(p->child[1]!=NULL)
            queue[++r]=p->child[1];
        if(p->child[2]!=NULL)
            queue[++r]=p->child[2];
	}
}
int cmp(const void*a,const void*b){
	checkptr p1 = (checkptr)a;
    checkptr p2 = (checkptr)b;
    if(p1->flow!=p2->flow)
        return p2->flow - p1->flow;
    else
        return p1->num - p2->num;
}
int main()
{
	int m,n,i=0;
	while(1){
		scanf("%d",&n);
		if(n==-1)break;
		else{
			i=0;
			airport_gate[n].num=n;
			while(1){
				scanf("%d",&m);
				if(m==-1)break;
				else{
					airport_gate[n].child[i]=(Tree*)malloc(sizeof(Tree));
					airport_gate[m].num=m;
					airport_gate[n].child[i++]=&airport_gate[m];
				}
			}
		}
	}
	select(&airport_gate[100]);
	F(i,0,gatenum-1){
		scanf("%d%d",&airport_check[i].num,&airport_check[i].flow);
	}
	qsort(airport_check,gatenum,sizeof(airport_ch),cmp);
	F(i,0,gatenum-1){
		printf("%d->%d\n",airport_check[i].num,after[i]);
	}
	return 0;	
}