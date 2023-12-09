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
#define N 110
int M=2017;
int n,m,T;
long long ans=0;
struct matrix{
    int n,m,c[N][N];
    matrix()
    {
        n=m=0;
        memset(c,0,sizeof(c));
    }//初始化
};
matrix t;
matrix operator * (const matrix &A,const matrix &B)
{
    matrix C;
    C.n=A.n;C.m=B.m;
    for(int i=0;i<=C.n;i++)
        for(int j=0;j<=C.m;j++)
            for(int k=0;k<=A.m;k++)
            {
                C.c[i][j]=(C.c[i][j]+A.c[i][k]*B.c[k][j])%M;
            }
    return C;
}
matrix ksm(matrix a,int b){
	matrix res;
    res.n=res.m=n;
    F(i,0,n)
    res.c[i][i]=1;
    while(b){
        if(b&1)
        res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    t.n=n ;t.m=n ;
	F(i,0,n)
    t.c[i][i]=1;
    F(i,1,n)
    t.c[i][0]=1;
    F(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        t.c[u][v]=1;
		t.c[v][u]=1;
    }
    scanf("%d",&T);
    matrix Ans = ksm(t,T);
    F(i,0,n)
    ans=((ans+Ans.c[1][i])%M);
    printf("%lld",ans);
    return 0;
}