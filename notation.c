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
char s[110];
int main()
{
	int i=0,j=0,l,flag=0;
	scanf("%s",s);
	char*p1,*p2,*p;
	p1=s;
	p2=strchr(s,'.');
	l=strlen(s);
	if(p2==NULL){
		if(l>1)
		printf("%se0",s);
		else{
			printf("%c.",s[0]);
			F(i,1,l-1)
			printf("%c",s[i]);
			printf("e%d",l-1);
		}
	}//无小数点
	else{
		if(p2-p1==1){
			if(s[0]>'0')
			printf("%se0",s);
			else{
			for (i=p2-p1+1; i<l; i++)
                {
                    if (s[i]!='0'&&flag==0)
                    {
                        p = &s[i];
                        flag = 1;
                        if (i==l-1)
                        {
                            printf("%c",s[i++]);
                        }
                        else
                            printf("%c.",s[i++]);
                    }
                    if (flag&&i<l)
                    {
                        printf("%c",s[i]);
                    }
                }//超小
                printf("e%d",p2-p);
			}
		}//一位
		else{
			p=&s[1];
			printf("%c.",s[0]);
			FD(i,1,l){
				if(s[i]!='.')
			printf("%c",s[i]);
			}
			printf("e%d",p2-p);
		}//大小数
	}
	return 0;
}