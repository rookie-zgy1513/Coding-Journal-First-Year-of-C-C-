#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct Node{
char data;
struct Node *Lchild;
struct Node *Rchild;
}BiTNode,*Bitree;

void PreTree(Bitree T)  //后序输出树
{   if(T==NULL) return;

     PreTree(T->Lchild);
     PreTree(T->Rchild);
     printf("%c",T->data);

}
char pre[MAX];
char mid[MAX];

int MidFind(int left,int right,char MID)  
{
    for(int i=left;i<=right;i++)
    {
        if(mid[i]==MID) return i;
    }
    return 0;
}

void Create(int left,int right,int *i,BiTNode **T)  //此题建立树得先将孩子结点赋NULL，因为没有用户输入以确定什么时候把某个具体的结点赋为NULL
{//这是第一种创建二叉树的写法（二级指针法）
//这种感觉是把指针送进函数处理
    *T=(Bitree)malloc(sizeof(BiTNode));
    (*T)->data=pre[*i];
    (*T)->Lchild=NULL; 
    (*T)->Rchild=NULL;
    (*i)++;
    int midnumber =  MidFind(left,right,(*T)->data);
    if(midnumber>left)
    {
        Create(left,midnumber-1,i,(&((*T)->Lchild)));
    }
    if(midnumber<right)
    {
        Create(midnumber+1,right,i,(&((*T)->Rchild)));
    }

}

BiTNode* Create2(int left,int right,int *i)
{//第二中创建方式（注意返回！！！）  
//这种感觉是把指针让函数处理（自己不进去）
BiTNode *T;
    T=(Bitree)malloc(sizeof(BiTNode));
    T->data=pre[*i];
    T->Lchild=NULL;
    T->Rchild=NULL;
    (*i)++;
    int midnumber =  MidFind(left,right,T->data);
    if(midnumber>left)
    {
        T->Lchild = Create2(left,midnumber-1,i);
    }
    if(midnumber<right)
    {
        T->Rchild = Create2(midnumber+1,right,i);
    }
    return T;

}
int main()
{
    memset(pre,0,MAX);
     memset(mid,0,MAX);
     gets(pre);
     gets(mid);
     int left,right,len,i=0;
     len=strlen(pre);
     left=0;
     right=len-1;

     BiTNode *T=(Bitree)malloc(sizeof(BiTNode));   //这里可以不用分配空间，因为在函数里会进行分配
     Create(left,right,&i,&T);

     PreTree(T);
     return 0;
}

