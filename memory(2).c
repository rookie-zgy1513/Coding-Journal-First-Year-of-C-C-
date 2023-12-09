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
	int ad;		//地址 
	int data;	//存储空间 
	struct node *next;
};
typedef struct node Node;
typedef struct node *Nodep;
Nodep head=NULL,p,t,q,o,r;
int n,i,j,ad,data,a,flag=0;
int main()
{	
	scanf("%d",&n);
	while(n--) 	//创建循环链表 
	{
		scanf("%d %d",&ad,&data);
		if(head == NULL)
		{
			p=(struct node *)malloc(sizeof(struct node ));
			head = p;
		}
    	else
		{
        	p->next =(struct node *)malloc(sizeof(struct node));
       	 	p = p->next;
    	}
    	p->ad=ad;
		p->data=data;
		p->next=NULL;
	}
	p->next=head; 	//头尾相连 
	o=p;			//o的后继节点是 p (o 是用来记录 p的踪迹的) 
	p=head;			//	p指向头 
	while(~scanf("%d",&a))
	{
		r=NULL;
		int min=0x3fffffff;
		flag=0;
		if(a==-1) //操作结束 
		{
			break;
		}
		if(o->next->data==a){
			o->next=p->next;
			q=p;
			p=p->next;
			free(q);
		}
		else{
			t=p;
			if(p->data>a)
			{
				min=p->data;
				r=o;
				flag=1;
			}
			while(p->next!=t){ //循环一圈 
				if(p->next->data>=a&&p->next->data<min)
				{
					min=p->next->data;
					r=p;
					flag=1;
				}
				o=p;	//跟踪 p 
				p=p->next;
			}
				if(flag==0&&p->next==t) //如果循环一圈也没有找到符合标准的 
				{
					o=p;p=t; //重置 
				}
				else{
					if(min==a){
					o=r;p=r->next;
					o->next=p->next;
					q=p;
					p=p->next;
					free(q);  	//删除节点 
					}
					else{
					o=r;
					p=o->next;
					p->data=p->data-a;
				  }
					
				} 
		}
	}
	if(p!=NULL){
	if(p->data)
	printf("%d %d\n",p->ad,p->data); //输出头节点信息 
	t=p->next;
	while(t!=p)
	{ 
	if(t->data)
		printf("%d %d\n",t->ad,t->data); //输出之后一圈的信息 
		t=t->next;
	}
  }
	
	return 0;
}

