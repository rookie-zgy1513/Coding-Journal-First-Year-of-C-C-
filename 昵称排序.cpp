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
int cmp(const void *p1, const void *p2) {
    char *a = (char *)p1; //将p1强制转换为char*类型的指针
    char *b = (char *)p2; //将p2强制转换为char*类型的指针
    return strcmp(a, b); //返回两个字符串的字典序大小
}
char s[100][100];
int main()
{
	int i=0,n;
	while(scanf("%s",s[i])!=EOF)
	{
		i++;
	}
	n=i;
	qsort(s,n,sizeof(s[0]),cmp);
	FD(i,0,n)
	printf("%s\n",s[i]);
	return 0;
}