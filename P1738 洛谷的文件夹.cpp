#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int i=(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int n,ans=0,l;
struct info{
	struct info *l,*r;
	char a[105];
};
struct info *root;
char s[105],r[105];
void dfs(int i,struct info* &p,bool flag,char r[]){
	if(!s[i]&&flag)return ;
	int j=i;
	if(flag){
		for(j=i+1;s[j]&&s[j]!='/';j++)
		r[j-i+1]=s[j];
		l=j-i+1;r[l]='\0';
	}
	if(p&&strcmp(p->a,r))
	dfs(j,p->r,false,r);
	else{
		if(!p){
			p=new struct info;
			strcpy(p->a,r);
			ans++;
			p->r=p->l=NULL;
		}
		dfs(j,p->l,true,r);
	}


}
int main(){
	scanf("%d",&n);
	F(i,1,n){
		scanf("%s",s);
		dfs(0,root,true,r);
		printf("%d\n",ans);
	}
	return 0;
}