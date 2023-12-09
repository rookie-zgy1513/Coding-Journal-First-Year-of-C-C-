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
int a[15]={0};
int  book[15]={0};
int n;
void dfs(int pos,int x)
{
    if(x==0)
    {
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
 		return;
		 }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            a[pos]=i;
            book[i]=1;
            dfs(pos+1,x-1);
            a[pos]=0;
            book[i]=0;
        }
    }
}
int main()
{
	scanf("%d",&n);
    dfs(1,n);
    return 0;
}