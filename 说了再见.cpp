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
char s[1010][110];
char name[1010][110];
int main()
{
	int n,m,flag=0,cnt=0;
	scanf("%d%d",&n,&m);
	F(i,1,n)
	scanf(" %[^\n]",s[i]);
	F(j,1,m)
	scanf(" %s",name[j]);
	F(i,1,m){
		flag=0;
		F(j,1,n){
			if(strstr(s[j],name[i])!=NULL)
			flag++;
		}
		if(flag==0){
		printf("%s ",name[i]);
		cnt++;
		}
		
	}
	if(!cnt)
	printf("Enjoy the scenery and we will meet again.");
	return 0;
}