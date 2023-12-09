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
char*p1,*p2;
int l;
char s[220];
char s1[220];
void string_rev(char s[])
{
    int hi = p2-s+l, low = p2-s;//定义hi和low的目的就是方便循环交换数据
    char temp;//只是一个工具人而已
    for (hi--; hi>low; low++,hi--)//头尾交换，以hi>low作为循环结束的条件，防止循环回去等于没交换，例如一个字符串有五个字符则每次交换（1，5）（2，4），3不交换。
    {
        temp=s[low];
        s[low]=s[hi];
        s[hi]=temp;
    }
}
int main()
{
	scanf("%s %s",s,s1);
	p1=s;
	l=strlen(s1);
	while(strstr(p1,s1)!=NULL){
		p2=strstr(p1,s1);
		string_rev(s);
		p1=p2+l;
		}
	printf("%s",s);
	return 0;
}