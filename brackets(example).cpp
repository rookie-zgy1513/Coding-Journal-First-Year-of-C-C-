#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct stack{    	     //顺序栈的结构体 
	int top;    		 //栈顶 
	char data[2000];	 //栈内的括号 
	int loc[2000];  	 // 栈内括号所对应的行号 
};
struct stack s,ss;       //s用来检查括号，ss是一个简单的数组。用来记录出现过的括号 
char a[2000];            //存储每一行的内容 
char *p,*pp,ch;          // p 和  pp是找到每一行的注释  
int i,j,line=0,flag=0,len;     // flag为标志变量，判断是否有明显的冲突 
void check();
int min(int x,int y)
{
	return x>y?y:x;
}
int main()
{	
	FILE *fp = fopen("example.c","r");
	s.top=0,ss.top=0;              //初始化两个栈 
	while (fgets(a,2000,fp) != NULL)
	{
		line++;                    //每读一行，行号增加 
		check();                   //进行检查 
		if(flag==1)                //有明显的冲突 
		{
			if(ch=='(')            // ******小心此处******，( 和 { 在有明显冲突时输出的行号不一样 
					printf("without maching '%c' at line %d",ch,s.loc[s.top-1]);
			else	printf("without maching '%c' at line %d",ch,line);
			break;
		}
	}
	if(flag==0)       //没有明显冲突 
	{
		if(s.top==0)         //判断栈顶是否为空 
		{
			puts(ss.data);   
		}
		else  //如果栈顶不为空，说明栈中还有未匹配的元素 
		{ 
			printf("without maching '%c' at line %d",s.data[s.top-1],s.loc[s.top-1]);
		}
	} 
	
	return 0;
}
void check()
{
	p=strstr(a,"//");   //  p  和   pp 确定每行需要检查的最大长度 
	pp=strstr(a,"/*");
	if(p==NULL && pp==NULL)
	{
		len=strlen(a);
	}
	else if(p==NULL && pp!=NULL)
	{
		len=pp-a;
	}
	else if(p!=NULL && pp==NULL)
	{
		len=p-a;
	}
	else if(p!=NULL && pp!=NULL)
	{
		len=min(p-a,pp-a);
	}
	//确定最大长度len 
	for(i=0;i<len;i++)
	{
		if(a[i]=='(')          
		{
			s.data[s.top]='(';   //压栈 
			ss.data[ss.top]='(';
			s.loc[s.top]=line;   //记录行号 
			s.top++,ss.top++;
		}
		else if(a[i]==')')
		{
			ss.data[ss.top]=')'; 
			ss.top++;
			if(s.data[s.top-1]=='(')  //检查是否与栈顶括号匹配 
			{
				s.top--;     //匹配则弹出匹配的括号 
			}
			else
			{
				ch=')';   //记录不匹配的括号 
				flag=1;   //是很明显的不匹配 
				break;
			}
		}
		else if(a[i]=='{')
		{
			ss.data[ss.top]='{';
			ss.top++;
			if(s.data[s.top-1]!='(')   // { 之前不能是  ( 
			{
				s.data[s.top]='{';
				s.loc[s.top]=line;
				s.top++;
			}
			else
			{
				ch='(';  //记录不匹配的括号 
				flag=1;  //是很明显的不匹配 
				break;
			}
		}
		else if(a[i]=='}')
		{
			ss.data[ss.top]='}';
			ss.top++;
			if(s.data[s.top-1]=='{')//检查是否与栈顶括号匹配
			{
				s.top--;  //匹配则弹出匹配的括号
			}
			else
			{
				ch='}'; //记录不匹配的括号 
				flag=1; //是很明显的不匹配 
				break;
			}
		}
		else if(a[i]==39)  //是单引号 
		{
			p=strchr(a+i+1,39);
			if(p!=NULL) i=p-a;   //直接跳过单引号的内容 
			else continue;
		}
		else if(a[i]==34)  // 是双引号 
		{
			p=strchr(a+i+1,34);
			if(p!=NULL) i=p-a;  //直接跳过双引号的内容 
			else continue;
		}
	}
}
