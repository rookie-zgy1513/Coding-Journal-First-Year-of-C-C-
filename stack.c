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
#define MAXSIZE 100
typedef struct stack{
    int num[MAXSIZE];
    int top;
}stack;
stack s;
void initialize(stack *s)
{
    s->top = 0;
}
int is_empty(stack *s)
{
    return s->top==0;
}
int is_full(stack *s)
{
    return s->top==MAXSIZE-1;
}
void push_stack(stack *s, int item)
{
    if (is_full(s))
    {
        printf("error ");
        return;
    }
    s->num[s->top++] = item;
}
void pop_stack(stack *s)
{
    if (is_empty(s))
    {
        printf("error ");
        return;
    }
    s->top--;
}
int get_top(stack *s)
{
    return s->num[s->top-1];
}
int main()
{
	initialize(&s);
	int op;
	int num;
	while (scanf("%d",&op)!=-1)
    {
    	if(op==-1)break;
        switch (op)
        {
            case 1:
                scanf("%d",&num);
                push_stack(&s, num);
                break;
                
            case 0:
            	if(is_empty(&s))
            	pop_stack(&s);
            	else{
				printf("%d ",get_top(&s));
                pop_stack(&s);
				}
                break;
        }
    }
    return 0;
}