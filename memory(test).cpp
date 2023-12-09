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
struct node{
	int add;
	int space;
	struct node* link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr head=NULL,rear=NULL;
Nodeptr p,r,o;
Nodeptr create(Nodeptr head,int ad,int sp){
	Nodeptr q;
	q=(Nodeptr)malloc(sizeof(Node));
	q->add=ad;
	q->space=sp;
	q->link=NULL;
	if(head==NULL){
		head=q;
		p=head;
	}
	else{
		p->link=q;
		p=q;
	}
	return head;
}
int main()
{
	int n,ad,sp,flag=0;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d%d",&ad,&sp);
		head=create(head,ad,sp);
	}
	p->link=head;
	r=p;
	while(scanf("%d",&sp)!=-1){
		if(sp==-1)break;
		flag=0;
		if(r->link->space>=sp){
			flag=1;
			if(r->link->space-sp){
				r->link->space=r->link->space-sp;
			}
			else{
				p=r->link;
				r->link=p->link;
				free(p);
			}
		}
		else{
			for(o=r->link;o!=r;o=o->link){
				if(o->link->space>=sp){
					flag=1;
					break;
				}
			}
			if(flag){
				if(o->link->space-sp){
					o->link->space=o->link->space-sp;
					r=o;
				}
				else{
					p=o->link;
					r=o;
					r->link=p->link;
					free(p);
				}
			}
		}
	}
	if(r!=NULL){
		if(r->link->space)
		printf("%d %d\n",r->link->add,r->link->space);
		for(o=r->link;o!=r;o=o->link){
			if(r->link->space)
			printf("%d %d\n",o->link->add,o->link->space);
		}
	}
	return 0;
}
