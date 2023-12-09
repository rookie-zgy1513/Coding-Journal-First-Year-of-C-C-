#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 1000
typedef struct candl{
	int ch;
	int line;
}candl,*Candl;

candl stack[1000],notation[1000],ans[1000];
int top=-1,topa=-1;

int push(Candl ptr)
{
	if(top==M-1)
		return 0;
	else
	{
		top++;
		stack[top].ch=ptr->ch;
		stack[top].line=ptr->line;
		return 1;
	}
}

int pusha(Candl ptr)
{
	if(topa==M-1)
		return 0;
	else
	{
		topa++;
		ans[topa].ch=ptr->ch;
		ans[topa].line=ptr->line;
		return 1;
	}
}

int pop(Candl ptr)
{
	if(top==-1)
		return 0;
	else
	{
		ptr->ch=stack[top].ch;
		ptr->line=stack[top].line;
		top--;
		return 1;
	}
}

int main()
{
	int line=0,length=0;
	FILE *input=fopen("example.c","r");
	char buffer[1000];
	while(fgets(buffer,1000,input)!=NULL)					//��ȡ������Ч���ţ�����notation������ 
	{
		line++;
		int i,flag_zhuanyi=0;
		for(i=0;buffer[i]!='\0';i++)
		{
			if(buffer[i]=='{'||buffer[i]=='}'||buffer[i]=='('||buffer[i]==')'||buffer[i]=='\''||buffer[i]=='\"'||buffer[i]=='/'||buffer[i]=='*'/*||buffer[i]=='\\'||flag_zhuanyi==1*/)
			{
				notation[length].ch=buffer[i];
				notation[length].line=line;
				length++;
			/*	flag_zhuanyi=0;								//��ȡת���ַ��������ַ� 
				if(buffer[i]=='\\')
				{
					flag_zhuanyi=1;
				}
			*/
			}
		}
	}
	fclose(input);
	int i;
/*	for(i=0;i<length;i++)
	{
		printf("%c %d\n",notation[i].ch,notation[i].line);
	}
*/	
	i=0;
	int flag_danyin=0,flag_shuangyin=0,flag_shuangxie=0,line_shuangxie,flag_xiexing=0;
	while(i<length)
	{
		if(flag_shuangxie==1)
		{
			if(notation[i].line!=line_shuangxie)
			{
				flag_shuangxie=0;
			}
			else
			{
				i++;
				continue;
			}
		}
		if(flag_xiexing==1)
		{
			if(notation[i].ch=='*'&&notation[i+1].ch=='/'&&notation[i].line==notation[i+1].line)
			{
				flag_xiexing=0;
			}
			else
			{
				i++;
				continue;
			}
		}
		if((notation[i].ch=='{'||notation[i].ch=='(')&&flag_danyin==0&&flag_shuangyin==0&&flag_shuangxie==0&&flag_xiexing==0)
		{
			push(&notation[i]);
			pusha(&notation[i]);
//			printf("    %c   %d\n",ans[topa].ch,ans[topa].line);
			if(top>=1)
			{
				if(stack[top].ch=='{'&&stack[top-1].ch=='(')
				{
					printf("without maching '%c' at line %d",stack[top-1].ch,stack[top-1].line);
					return 1;
				}
			}
		}
		else if((notation[i].ch=='}'||notation[i].ch==')')&&flag_danyin==0&&flag_shuangyin==0&&flag_shuangxie==0&&flag_xiexing==0)
		{
			if(top==-1)
			{
				printf("without maching '%c' at line %d",notation[i].ch,notation[i].line);
				return 1;
			}
			if((notation[i].ch=='}'&&stack[top].ch=='{')||(notation[i].ch==')'&&stack[top].ch=='('))
			{
				pusha(&notation[i]);
//				printf("    %c   %d\n",ans[topa].ch,ans[topa].line);
				Candl temp=(Candl)malloc(sizeof(candl));
				pop(temp);
				free(temp);
			}
			else
			{
				printf("without maching '%c' at line %d",notation[i].ch,notation[i].line);
				return 1;
			}
		}
		else if((notation[i].ch=='\''||notation[i].ch=='\"')&&flag_shuangxie==0&&flag_xiexing==0) 
		{
			if(notation[i].ch=='\''&&flag_shuangyin==0)
			{
			//	if(notation[i-1].ch!='\\'||(notation[i-1].ch=='\\'&&notation[i-2].ch=='\\'))
					flag_danyin=1-flag_danyin;
			}
			if(notation[i].ch=='\"'&&flag_danyin==0)
			{
				flag_shuangyin=1-flag_shuangyin;
			}
		}
		else if(notation[i].ch=='/'&&notation[i+1].ch=='/'&&notation[i].line==notation[i+1].line&&flag_danyin==0&&flag_shuangyin==0&&flag_xiexing==0&&flag_shuangxie==0)
		{
			flag_shuangxie=1;
			line_shuangxie=notation[i].line;
			i++;
		}
		else if(notation[i].ch=='/'&&notation[i+1].ch=='*'&&notation[i].line==notation[i+1].line&&flag_danyin==0&&flag_shuangyin==0&&flag_shuangxie==0&&flag_xiexing==0)
		{
			flag_xiexing=1;
			i++;
		}
		i++;
	}
	if(top==0)
	{
		printf("without maching '%c' at line %d",stack[top].ch,stack[top].line);
		return 1;
	}
	else if(top==-1)
	{
		int i;
		for(i=0;i<=topa;i++)
		{
			printf("%c",ans[i].ch);
		}
	}
	return 0;
}
