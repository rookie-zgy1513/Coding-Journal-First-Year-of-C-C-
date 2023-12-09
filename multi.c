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
	int pow;
	struct node* link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr list=NULL,result=NULL;
Nodeptr p;
Nodeptr create(Nodeptr list, int x1, int x2)
{
	Nodeptr q;
    q = (Nodeptr)malloc(sizeof(Node));
    q->num = x1;
    q->pow = x2;
    q->link = NULL;
    if (list==NULL){
	list = q;
	p = q;
	}   
    else
    {
        p->link = q;
        p = q;
    }
    return list;
}
Nodeptr insert(Nodeptr list, int x1, int x2)
{
	Nodeptr r;
    r = (Nodeptr)malloc(sizeof(Node));
    r->num = x1;
    r->pow = x2;
    r->link = NULL;
    Nodeptr p = NULL;
    Nodeptr q = NULL;
    for (p=list; p!=NULL&&p->pow>r->pow; q=p,p=p->link);
    if (p!=NULL && p->pow==r->pow)
        p->num += r->num;
    else
    {
        r->link = q->link;
        q->link = r;
    }
    return list;
}
void output(Nodeptr list)
{
    for (p=list;p!=NULL&&p->num!=0;p=p->link)
    printf("%d %d ",p->num,p->pow);
}
int main()
{
	int a,b,flag=0;
	char c=' ';
	Nodeptr p,q;
    p = (Nodeptr)malloc(sizeof(Node));
	while(c!='\n'){
		scanf("%d%d%c",&a,&b,&c);
		list=create(list,a,b);
	}
	//output(list);
	c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&a,&b,&c);flag++;
		if(flag==1){
			for(p=list;p!=NULL;p=p->link)
			result=create(result,a*p->num,b+p->pow);
		}
		else{
			for(p=list;p!=NULL;p=p->link)
			result=insert(result,a*p->num,b+p->pow);
		}	
	}
    output(result);
    return 0;
}