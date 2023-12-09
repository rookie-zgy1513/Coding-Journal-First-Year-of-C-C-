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
const int N = 1e7 + 100;
int T, x, ls;
int f[N], nx[N];
bool check(int x)//判断是否含有数字7
{
    while (x)
    {
        if (x % 10 == 7)
            return 1;
        x /= 10;
    }
    return 0;
}
void init()//预处理部分
{
    for (int i = 1; i <= N - 10; i++)
    {
        if (f[i])//如果被标记过，就跳过
            continue;
        if (check(i))//如果含有数字7，标记其倍数
        {
            for (int j = i; j <= N - 10; j += i)
                f[j] = 1;
            continue;
        }
        nx[ls] = i;//记录i
        ls = i;//更新ls
    }
}
int main()
{
    init();//先预处理
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&x);
        if (f[x])//被标记了输出-1，否则输出nx
            puts("-1");
        else
            printf("%d\n",nx[x]);
    }
    return 0;
}