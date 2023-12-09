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
struct Node{
    int number;
    int count;
    struct Node *left, *right;
    struct Node *parent;
};
int total=0, max=0;
struct Node *find;
struct Node *q=NULL;
struct Node* insert(struct Node* p,int num){
	if(p == NULL){
		p = (struct Node*)malloc(sizeof(struct Node));
		p->parent = q;
		p->left = NULL;
		p->right = NULL;
		p->count = 1;
		p->number = num;
		q=p;
	}
	else if(num<p->number){
		total++;
		p->left = insert(p->left,num);
	}
	else if(num>p->number){
		total++;
		p->right = insert(p->right,num);
	}
	else{
		total++;
		p->count++;
	}
	return p;
}
void post_order(struct Node*p){
	if(p!=NULL){
        post_order(p->left);
        post_order(p->right);
        if(p->count > max){
            max = p->count;
            find = p;
        }
    }
}
void print(struct Node * p){
    //printf("%d ",p->number);
    if(p->number > find->number){
    	printf("%d ",p->number);
		print(p->left);
	}
        
    else if(p->number < find->number){
    	printf("%d ",p->number);
		print(p->right);
	}
        
    else
        return ;
}
int main()
{
	int n,i,num;
	struct Node *root=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		root = insert(root,num);
	}
	post_order(root);
	printf("%d\n", total);
    print(root);
    printf("\n");
    return 0;
}