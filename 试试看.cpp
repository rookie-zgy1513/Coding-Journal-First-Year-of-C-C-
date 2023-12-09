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
#define eps 1e-6
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int main()
{
char str[] = "This is a sample string";
/*char *pchFirst, *pchLast;
pchFirst = strchr(str, 's'); //找出str中的第一个s的地址
pchLast = strrchr(str, 's'); //找出str中最后一个s的地址
if(pchFirst != NULL)
printf("first s found at %lld\n", pchFirst - str + 1); //计算第一个s在str中的位置
if (pchLast != NULL)
printf("last s found at %lld\n", pchLast - str + 1); //计算最后一个s在str中的位置*/
char s[100],s2[100];
char *p1,*p2;
p1=s;
p2=s2;
strcpy(p1,str);
strcpy(s2,"HELLO WORLD");
p2=p2+4;
strcpy(p2,str);
printf("%s\n%s",s,s2);
return 0;
}