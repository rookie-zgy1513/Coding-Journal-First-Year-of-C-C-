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
char s[500005][50];
char s1[3005][50];
int main()
{
	int n,t,m,x,j;
	int f=0,l=0;
	scanf("%d%d",&n,&t);
	F(i,1,n){
		scanf("%d",&m);
		itoa(m,s[i],10);
	}
	F(i,1,t){
		f=0;l=0;
		scanf("%d",&x);
		itoa(x,s1[i],10);
		printf("%s\n",s1[i]);
		F(j,1,n){
			if(strcmp(s[j],s1[i])==0){
				f=j;
			}break;
		}
		if(f==0){
			printf("-1\n");
		}
		else{
		for(j=n;j>=1;j--){
			if(strcmp(s[j],s1[i])==0){
				l=j;
			}break;
		}
		if(l==f)
		printf("%d\n",f);
		else
		printf("%d %d\n",f,l);
		}
		
	}
	return 0;
}