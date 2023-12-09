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
char s1[100100];
char s2[100100];
int main()
{
	int n,l;
	char *p1,*p2;
	while(scanf("%s",s1)!=EOF){
		p2=s1;p2++;
		if(strchr(p2,'1')==NULL)
		printf("overf1ow!\n");
		else{
		if(s1[0]-'0'==0)
			printf("1");
			else
			printf("0");
			l=strlen(s1);
			p1=strrchr(s1,'1');
			if(p1-s1==l-1){
				s1[l-1]='0';
			}
			else{
				s1[p1-s1]='0';
				F(i,p1-s1+1,l-1)
				s1[i]='1';
			}
			F(i,1,l-1){
				if(s1[i]=='0')
				printf("1");
				else
				printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}