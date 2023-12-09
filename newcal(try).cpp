#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define MaxSize 250
char suffix[MaxSize];
int n=0;
typedef int ElemType;
 
typedef struct {	//定义操作数栈
	ElemType data[MaxSize];
	int top;
}NumStack;
 
typedef struct {	//定义运算符栈
	char data[MaxSize];
	int top;
}StrStack;

/* 树结点的设计 */
typedef struct node
{
    /* 数字和运算符 */
    union
    {
        char op;
        int data;
    };
 
    struct node *lchild;
    struct node *rchild;
}TreeNode;
 
/* 树栈 */
typedef struct Tree_Stack
{
    TreeNode *buf[MaxSize];
    int n;
}TreeStack;
 
/* 创建空栈 */
TreeStack *create_empty_stack()
{
    TreeStack *pstack;
 
    pstack = (TreeStack *)malloc(sizeof(TreeStack));
    pstack->n = -1;
 
    return pstack;
}
 
/* 入栈 */
int push_stack(TreeStack *p, TreeNode *data)
{
    p->n++;
    p->buf[p->n] = data;
 
    return 0;
}
 
/* 出栈 */
TreeNode *pop_stack(TreeStack *p)
{
    TreeNode *data;
 
    data = p->buf[p->n];
    p->n --;
 
    return data;
}
 
/* 判断栈空 */
int is_empty_stack(TreeStack *p)
{
    if(p->n == -1)
        return 1;
    else
        return 0;
}
 
/* 创建后缀表达式树 */
TreeNode *create_express_tree(char *str, TreeStack *p)
{
    int i = 0;
    TreeNode *current;
    TreeNode *left, *right;
    while(str[i])
    {
    	char temp[MaxSize];	//用于将字符串数字转换为数值
		int j = 0, flag = 0;	//flag用于判断当前是否是数值
		while (isdigit(str[i]) || str[i] == '.') {
			temp[j++] = str[i++];
			flag = 1;
		}
        if (flag == 1)
        {
        	temp[j] = '\0';
            current = (TreeNode *)malloc(sizeof(TreeNode));
            current->data = atof(temp);
            current->lchild = NULL;
            current->rchild = NULL;
            push_stack(p, current);
        }
       if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            current = (TreeNode *)malloc(sizeof(TreeNode));
            current->op = str[i];
            right = pop_stack(p);
            left = pop_stack(p);
            current->lchild = left;
            current->rchild = right;
            push_stack(p, current);
        }
        else if (str[i] == ' ') {
			// 若为空格则继续扫描
		}
        i++;
    }
    return p->buf[p->n];
}
 
/* 打印结点 */
void print_node(TreeNode *p)
{
    if(p->lchild == NULL && p->rchild == NULL)
        printf("%d ", p->data);
    else
        printf("%c ", p->op);
}
 
/* 访问结点 */
int visit_node(TreeNode *p)
{
    print_node(p);
 
    return 0;
}
 void PostOrder(TreeNode *p)
{
    if(p != NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        visit_node(p);
    }
}

// 将运算符出栈，操作数栈依次出栈两个作为右操作数和左操作数，计算结果并入栈操作数栈
void Calculate(StrStack& StrS, NumStack& NumS) {
	char operate = StrS.data[StrS.top--];
	suffix[n++]=operate; //弹出的运算符是后缀表达式，输出显示一下
	suffix[n++]=' ';
	ElemType right = NumS.data[NumS.top--];
	ElemType left = NumS.data[NumS.top--];
	ElemType result;
	switch (operate) {
	case '+':result = left + right; break;
	case '-':result = left - right; break;
	case '*':result = left * right; break;
	case '/':result = left / right; break;
	}
	NumS.data[++NumS.top] = result;
}
 
 
// 将字符串表示的中缀表达式转换为后缀表达式输出，同时计算结果
void MiddleToSuffix(char str[]) {
	NumStack NumS;
	StrStack StrS;
	NumS.top = -1;	//初始化操作数栈
	StrS.top = -1;	//初始化运算符栈
	printf("后缀表达式为:");
	for (int i = 0; i < strlen(str); i++) {	//依次扫描字符串
		/* 1. 若为操作数，求后缀表达式则直接输出，计算值则压入操作数栈*/
		char temp[MaxSize];	//用于将字符串数字转换为数值
		int j = 0, flag = 0;	//flag用于判断当前是否是数值
		while (isdigit(str[i]) || str[i] == '.') {
			suffix[n++]=str[i];
			temp[j++] = str[i++];
			flag = 1;
		}
		if (flag == 1) {
			temp[j] = '\0';
			suffix[n++]=' ';
			NumS.data[++NumS.top] = atof(temp);	//操作数直接入操作数栈，同时输出显示
		}
		/* 2. 若为界限符，左括号则压入运算符栈，右括号则弹出运算符栈的运算符直到遇到左括号并输            　　　　　　　
　　　　　出显示，后缀表达式是不显示括号的；同时每次弹出一个运算符，则依次弹出操作数栈的两个操　　　　　　　　 
          作数分别作为右操作数和左操作数计算结果并压入操作数栈*/
		if (str[i] == '(') {
			StrS.data[++StrS.top] = str[i];
		}
		else if (str[i] == ')') {
			while (StrS.data[StrS.top] != '(') {
				Calculate(StrS, NumS);
			}
			StrS.top--;	//将左括号出栈
		}
		/* 3. 若为运算符，弹出运算符栈中优先级更大和同级的运算符直到栈空或左括号，同时输出弹出 
         的运算符以及计算结果，最后将该运算符入栈*/
		else if (str[i] == '+' || str[i] == '-') {	/*由于加法和减法优先级最低，故运算符栈 
                                                         栈顶只要是运算符都会一直出栈*/
			while (StrS.top != -1 && StrS.data[StrS.top] != '(') {
				Calculate(StrS, NumS);
			}
			StrS.data[++StrS.top] = str[i];
		}
		else if (str[i] == '*' || str[i] == '/') {	/*由于乘法和除法优先级最高，故只能运算 
                                                       符栈顶是乘法或除法才可以持续弹出*/
			while (StrS.top != -1 && StrS.data[StrS.top] != '(' && (StrS.data[StrS.top] == '*' || StrS.data[StrS.top] == '/')) {
				Calculate(StrS, NumS);
			}
			StrS.data[++StrS.top] = str[i];
		}
		else if (str[i] == ' ') {
			// 若为空格则继续扫描
		}
	}
	while(StrS.top != -1){	//若运算符栈不空则一直出栈到空，并计算结果，最终操作数栈中的元素即为最终计算结果
		Calculate(StrS, NumS);
	}
	printf("%s\n",suffix);
	printf("\n表达式的计算结果为:%d\n", NumS.data[NumS.top]);
}
 
void Practice() {
	char str[MaxSize];
	//TreeNode *root;
    //TreeStack *pstack;

	gets(str);
	MiddleToSuffix(str);
	//pstack = create_empty_stack();
    //root = create_express_tree(suffix, pstack);
	/*if(root!=NULL)
        visit_node(root);
    if(root->lchild!=NULL)
        visit_node(root->lchild);
    if(root->rchild!=NULL)
        visit_node(root->rchild);
    printf("\n");*/
    //PostOrder(root);

}
 
int main() {
	TreeNode *root;
    TreeStack *pstack;

	Practice();
	pstack = create_empty_stack();
    root = create_express_tree(suffix, pstack);
	if(root!=NULL)
        visit_node(root);
    if(root->lchild!=NULL)
        visit_node(root->lchild);
    if(root->rchild!=NULL)
        visit_node(root->rchild);
    printf("\n");
    //PostOrder(root);
	return 0;
}