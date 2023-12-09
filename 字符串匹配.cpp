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
char s1[110],s2[110];
int main()
{
	long long int cnt=0;
	char*p1,*p2;
	char c;
	p1=s1;
	scanf("%s",s1);
	scanf("%s",s2);
	c=s2[0];
	while((p2=strstr(p1,s2))!=NULL){
		cnt++;
		p1=p2+1;
	}
	printf("%lld",cnt);
	return 0;
}