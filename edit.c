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
#define MAXLENGTH 512
typedef struct edit{
    int operation;
    int position;
    char s[MAXLENGTH];
    int length;
}edit;
typedef struct stack{
    edit stack[MAXLENGTH];
    int top;
}stack;
stack Stack;
char s[MAXLENGTH];
void initstack(stack *s)
{
    s->top = -1;
}
int isempty(stack *s)
{
    return s->top==-1;
}
void pushstack(stack *s, edit temp)
{
    s->stack[++s->top] = temp;
}
void pop(stack *s)
{
    s->top--;
}
edit get_top(stack *s)
{
    return s->stack[s->top];
}
void insert(int pos,char tmp[],int num)
{
    char temp[MAXLENGTH];
    strcpy(temp,s+pos);
    strcpy(s+pos,tmp);
    strcpy(s+pos+num,temp);
}
void del(int pos, int num)
{
    char temp[MAXLENGTH];
    int length = strlen(s);
    if(num+pos>length)
        num = length-pos;
    strcpy(temp,s+pos+num);
    strcpy(s+pos,temp);
    s[length-num]='\0';
}
int main()
{
	initstack(&Stack);
	gets(s);
	int n;
	edit temp;
	scanf("%d",&n);
	int length;
	int i;
	int op;
	F(i,0,n-1){
		scanf("%d %d %s",&temp.operation,&temp.position,temp.s);
        length = strlen(temp.s);
        temp.length = length;
        pushstack(&Stack,temp);
	}
	int flag=0;
	while(1)
    {
        if (flag)
        {
            break;
        }
        scanf("%d",&op);
        switch (op)
        {
            case -1:
                flag = 1;
                break;
            case 1:
                scanf("%d %s",&temp.position,temp.s);
                temp.operation = 1;
                length = strlen(temp.s);
                temp.length = length;
                pushstack(&Stack,temp);
                insert(temp.position,temp.s,temp.length);
                break;
            case 2:
                scanf("%d %d",&temp.position,&temp.length);
                temp.operation = 2;
                pushstack(&Stack,temp);
                length = strlen(s);
                for( i=Stack.stack[Stack.top].position;i<length&&i<Stack.stack[Stack.top].position+Stack.stack[Stack.top].length;i++)
                {
                    Stack.stack[Stack.top].s[i-Stack.stack[Stack.top].position] = s[i];
                }
                del(temp.position,temp.length);
                break;
            case 3:
                if(isempty(&Stack))
                {
                    continue;
                }
                temp = get_top(&Stack);
                pop(&Stack);
                if(temp.operation==1)
                {
                    del(temp.position,temp.length);
                }
                else if(temp.operation==2)
                {
                    insert(temp.position,temp.s,temp.length);
                }
                break;
        }
    }
	printf("%s\n",s);
    return 0;
}