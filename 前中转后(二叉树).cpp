#include <stdio.h>
#include <stdlib.h>
int pre[23],in[23];
int k=0;
   int t=1;
typedef struct binarytree
{
    int data;
    struct binarytree *rChild;
   struct binarytree *lChild;
}binarytree,*tree;
void  buildtree(int l,int r,tree *root);
void postorder (tree root);
void  buildtree(int l,int r,tree *root)
{
 
 
int flag=-1;
int i;
for ( i = l; i <=r; i++){
 
    if (in[i]==pre[t])
    {
 
        flag=i;
		break;
    }
    
}
if(flag==-1) {return ;} 
t++;
*root=(binarytree *)malloc(sizeof(binarytree));
(*root)->data=in[i];
(*root)->lChild=NULL;
(*root)->rChild=NULL;
if(flag>l)buildtree(l,flag-1,&((*root)->lChild));
if(flag<r)buildtree(flag+1,r,&((*root)->rChild));
 
}
void postorder (tree root){      //求后序序列
    if(root){
	    	 
        postorder(root->lChild);
        postorder(root->rChild);
       printf("%5d",root->data);	
       
	}
}
 
void preorder (tree root){      //求前序序列
    if(root){
	    	 printf("%5d",root->data);
        postorder(root->lChild);
        postorder(root->rChild);
       	
       
	}
}
int main(){
    int n;
    int i;
 
    tree root;
       printf("请输入二叉树的结点数：\n");
    scanf("%d",&n);
    //fflush(stdin);
   printf("请输入二叉树的前序遍历数组的各个值：\n");
   for ( i = 1; i <=n; i++)
   {
       
    scanf("%d",&pre[i]);
    
   }
   //fflush(stdin);
    printf("请输入二叉树的中序遍历数组的各个值:\n");
   for ( i = 1; i <=n; i++)
   {  
    scanf("%d",&in[i]);
   }
   printf("后序遍历为：\n");
   buildtree(1,n,&root);
postorder(root);
	
}
/*对于指针 用来改变值 使用方法：（*变量名）
  普通变量用来遍历
二叉树在建立时要确保左右子树是否已经为空不然在遍历时会出现bug
*/