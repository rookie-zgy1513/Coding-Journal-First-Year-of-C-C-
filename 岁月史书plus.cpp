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
char s1[60],s2[60],s3[60];
int main()
{
	int n,l,m;
	char*p1;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%s",s1);
		scanf("%s",s2);
		scanf("%s",s3);
		l=strlen(s2);
		p1=strstr(s1,s2);
		if(strstr(s1,s2)){
			FD(j,0,l){
				s1[p1-s1+j]=s3[j];
			}
			printf("%s\n",s1);
		}
		else
		printf("I'll make this night never have happened!\n");
	}
	return 0;
}