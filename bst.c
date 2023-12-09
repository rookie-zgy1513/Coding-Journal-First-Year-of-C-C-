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
typedef struct node{
    int data;
    int layer;
    struct node *lchild;
    struct node *rchild;
}Node,*BTNodeptr;
BTNodeptr tree,p,q;
BTNodeptr root = NULL;
int n;
int layer;
BTNodeptr insertnode(BTNodeptr root, int item, int layer){
    layer++;
    if (root==NULL)
    {
        root = (BTNodeptr)malloc(sizeof(Node));
        root->data = item;
        root->lchild = NULL;
        root->rchild = NULL;
        tree = root;
        root->layer = layer;
    }
    else if (item<root->data)
            root->lchild = insertnode(root->lchild, item, layer);
    else if (item>=root->data)
            root->rchild = insertnode(root->rchild, item, layer);
    return root;
}
void output(BTNodeptr root){
    if (root!=NULL)
    {
        if (!(root->lchild)&&!(root->rchild))
        {
            printf("%d %d\n",root->data,root->layer);
        }
        output(root->lchild);
        output(root->rchild);
    }
    
}
int main()
{
	int m;
	scanf("%d",&n);
	F(i,0,n-1){
		scanf("%d",&m);
		root = insertnode(root,m,layer);
	}
	output(root);
	return 0;
}