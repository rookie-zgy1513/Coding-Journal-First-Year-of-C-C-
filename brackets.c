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
#define MAXLENGTH 205
struct BRACKET{
    char ch;
    int position;
};
typedef struct BRACKET BRACKET;
BRACKET bracket[MAXLENGTH];
struct stack{
    BRACKET bracket[MAXLENGTH];
    int top;
};
typedef struct stack stack;
stack stacks;
int line,length;
char readin[MAXLENGTH];//读入
char store[MAXLENGTH];//准备输出
int type;
void initialize(stack *s)
{
    s->top = -1;
}
void error(char s[])
{
    printf("%s\n",s);
    exit(-1);
}
int is_full(stack *s)
{
    return s->top==MAXLENGTH-1;
}
int is_empty(stack *s)
{
    return s->top==-1;
}
void push(stack *s, char c, int line)
{
    if (is_full(s))
        error("Stack is full!");
    else
    {
        s->bracket[++s->top].ch = c;
        s->bracket[s->top].position = line;
    }
}
void pop(stack *s)
{
    if (is_empty(s))
        error("stack is empty!");
    else
    {
        s->bracket[s->top].ch = '\0';
        s->bracket[s->top].position = 0;
        s->top--;
    }
}
int judge(char s)
{
    switch (s)
    {
        case '(':
            return 1;
        case '{':
            return 1;
        case '/':
            return 1;
        case '*':
            return 1;
        case '"':
            return 1;
        case ')':
            return 1;
        case '}':
            return 1;
    }
    return 0;
}
int main()
{
	FILE *fp;
    fp = fopen("example.c", "r");
    int i = 0, j = 0;
	initialize(&stacks);
	while (fgets(readin, MAXLENGTH, fp)!=NULL)//避免注释里有'\n'导致漏行
    {
        line++;
        length = strlen(readin);
        type = 0;
        for (i=0; i<length; i++)
        {
            if (type==4)
                continue;
            if (!judge(readin[i]))
                continue;
            if ((readin[i]=='('||readin[i]=='{') && type!=3&&type!=5)
                type = 1;
            if ((readin[i]==')'||readin[i]=='}') && type!=3&&type!=5)
                type = 2;
            if ((readin[i]=='/'&&readin[i+1]=='*') && type!=3&&type!=5)
                type = 3;//二级注释
            if ((readin[i]=='/'&&readin[i+1]=='/') && type!=3&&type!=5)
                type = 4;//最优先级注释
            if (readin[i]=='"'&&type!=5)
            {
                type = 5;
                continue;
            }//另一种“注释”
            if (type==5&&readin[i]!='"')
                continue;
            if (readin[i]=='"'&&type==5)
            {
                type = 0;
                continue;
            }//重置注释
            if (type==3&&readin[i]=='*'&&readin[i+1]=='/')
                type = 0;//重置注释
            if (readin[i]=='{'&&stacks.bracket[stacks.top].ch=='(')
            {
                type = -1;
                break;
            }//顺序不对，特判1
            if (readin[i]==')'&&stacks.bracket[stacks.top].ch=='{')
            {
                type = -1;
                push(&stacks, readin[i], line);
                break;
            }
            if (type==3)
                continue;
            if (type==1||type==2)
            {
                store[j++] = readin[i];
                if (readin[i]==')'&&stacks.bracket[stacks.top].ch=='(')
                    pop(&stacks);
                else if (readin[i]=='}'&&stacks.bracket[stacks.top].ch=='{')
                    pop(&stacks);
                else
                    push(&stacks, readin[i], line);
                type = 0;
            }
        }
        if (type==-1)
            break;
        strcpy(readin,"\0");
    }
	if (stacks.top==-1)
        printf("%s\n",store);
    else
        printf("without maching '%c' at line %d\n",stacks.bracket[stacks.top].ch,stacks.bracket[stacks.top].position);
    fclose(fp);
    return 0;
}