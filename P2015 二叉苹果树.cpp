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
typedef struct node{
	int n;
	int apple;
	int next;
}node;
node N[205];
int dp[105][105];
int head[105],n,m,tot=0;
void add(int x,int y,int z){
	N[++tot].n=y;
	N[tot].apple=z;
	N[tot].next = head[x];
	head[x]=tot;
}
void dfs(int root,int bo,int apple) {
	int flag=0;
    int son[101]={0},cnt=0; 
    for(int find=head[root];find;find=N[find].next)
    {
        if(N[find].n!=bo)
        {
        	flag=1;
            son[++cnt]=find;
            dfs(N[find].n,root,N[find].apple);
        }
    }
    if(!flag) 
    {
        return;
    }
    for(int i=1;i<=m;i++) 
    {
        for(int j=0;j<=i;j++)
        {
        	int t1=0;
        	if(j-1>=0) t1+=N[son[1]].apple;  
        	if(i-j-1>=0) t1+=N[son[2]].apple;
        	if(j!=0)
         		dp[root][i]=MAX(dp[root][i],dp[N[son[1]].n][j-1]+t1+dp[N[son[2]].n][i-j-1]);  
         	else 
         		dp[root][i]=MAX(dp[root][i],dp[N[son[2]].n][i-j-1]+t1);
        }
    }
}
int main(){
	int x,y,z;
	scanf("%d%d",&n,&m);
	F(i,1,n-1){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0,0);
	printf("%d",dp[1][m]);
	return 0;

}