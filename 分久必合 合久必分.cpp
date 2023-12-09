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
char str[110];
int main()
{
	int n,op,l;
	scanf("%d",&n);
	F(i,1,n){
		scanf("%d",&op);
		if(op==0){
			scanf(" %[^\n]",str);
			printf("%s\n",str);
		}
		if(op==1){
			scanf(" %[^\n]",str);
			l=strlen(str);
			FD(j,0,l){
				if(str[j]!=' ')
				printf("%c",str[j]);
				else
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}