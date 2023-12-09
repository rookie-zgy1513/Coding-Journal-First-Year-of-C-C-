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
	int num;
	int cnt;
	struct node* link;
};
typedef struct node Node;
typedef struct node *Nodeptr;
Nodeptr list=NULL;
long long int cmp=0;
int search(int m)
{
    struct node *p = NULL, *q = NULL,*r = NULL,*o=NULL;
    o = (struct node*)malloc(sizeof(struct node));
    q = (struct node*)malloc(sizeof(struct node));
    o->num=m;o->cnt=1;o->link=NULL;
    if(list==NULL){
    	list=o;
    	return 1;
	}
	else{
		for (p=list; p!=NULL; q=p,p=p->link){
    	cmp++;
        if(m==p->num){
        	if(p==list){
			p->cnt++;
			return 1;
			}
        	
        	else{
        	p->cnt++;
			q->link=p->link;
        	o->cnt=p->cnt;
        	o->link=list;
        	list=o;
        	free(p);
        	return 1;
			}
        }
    	}
    	q->link=o;
    	return 1;
  }
}
int getLength(Nodeptr list)
{
    Nodeptr p;
    int n = 0;
    for (p=list; p!=NULL; p=p->link)//用到链表的遍历
    {
        n++;
    }
    return n;
}
/*void output(Nodeptr n){
	Nodeptr p;
	p=n;
	for(p=n;p!=NULL;p=p->link){
		printf("%d ",p->num);
	}
	printf("\n");
}*/
int main()
{
	Nodeptr p;
	int n,m,l;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d",&m);
		search(m);
	//	output(list);
		
	}
	l=getLength(list);
	p=list;
	if(l>=5){
		int i=1;
		while(i<=5){
			printf("%d %d\n",p->num,p->cnt);
			p=p->link;
			i++;
		}
	}
	else{
		for(p=list;p!=NULL;p=p->link){
			printf("%d %d\n",p->num,p->cnt);
		}
	}
	printf("%lld",cmp);
	return 0;
}
