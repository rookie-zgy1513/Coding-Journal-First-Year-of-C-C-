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
#define N 998244353
long long int cnt;
char s[100005];
char name[100];
void search(char*s1,int n,int m){
	int l1,l2,i=0,j=0;
	l1=strlen(s1);
	if(!m){
		cnt=(cnt+1)%N;
		return ;
	}
	for(i=0;i<l1;i++){
		if(strchr(s1+i,name[n])!=NULL){
			search(s1+i+1,n+1,m-1);
		}
		return ;
	}
	
}
int main()
{
	int l;
	scanf("%s",s);
	scanf("%s",name);
	l=strlen(name);
	search(s,0,l);
	printf("%lld",cnt);
	return 0;
	
}