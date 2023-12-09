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
int a[50][50];
int main()
{
    int i=0, j=0, k=0;
    int flag = 0;
    FD(i,0,19)
    FD(j,0,19)
    scanf("%d",&a[i][j]);
    F(i,0,19)
    a[19][i]=3;
    F(i,0,19)
    a[i][19]=3;//设置棋盘边界
    for (i=0; i<19; i++)//行
    {
        if (flag)
        {
            break;
        }
        for (j=1; j<=15; j++)
        {
            if (flag)
            {
                break;
            }
            else if (!flag && a[i][j]!=0)
            {
                for (k=1; k<4; k++)
                {
                    if (a[i][j]==a[i][j+k] && k!=3)
                    {
                        continue;
                    }
                    if (a[i][j]!=a[i][j+k])
                    {
                        break;
                    }
                    
                    if ((k==3&&a[i][j-1]==0) || (k==3&&a[i][j+4]==0))
                    {
                        flag = 1;
                        printf("%d:%d,%d\n",a[i][j],i+1,j+1);
                        break;
                    }
                }
            }
        }
    }
    for (j=0; j<19; j++)//列
    {
        if (flag)
        {
            break;
        }
        for (i=1; i<=15; i++)
        {
            if (flag)
            {
                break;
            }
            else if (!flag && a[i][j]!=0)
            {
                for (k=1; k<4; k++)
                {
                    if (a[i][j]!=a[i+k][j])
                    {
                        break;
                    }
                    if (a[i][j]==a[i+k][j] && k!=3)
                    {
                        continue;
                    }
                    if ((k==3&&a[i-1][j]==0) || (k==3&&a[i+4][j]==0))
                    {
                        printf("%d:%d,%d\n",a[i][j],i+1,j+1);
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    for (i=1; i<=15; i++)//左对角线
    {
        if (flag)
        {
            break;
        }
        for (j=1; j<=15; j++)
        {
            if (flag)
            {
                break;
            }
            else if(!flag && a[i][j]!=0)
            {
                for (k=1; k<4; k++)
                {
                    if (a[i][j]!=a[i+k][j+k])
                    {
                        break;
                    }
                    if (a[i][j]==a[i+k][j+k] && k!=3)
                    {
                        continue;
                    }
                    if ((k==3&&a[i-1][j-1]==0) || (k==3&&a[i+4][j+4]==0))
                    {
                        printf("%d:%d,%d\n",a[i][j],i+1,j+1);
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    for (i=1; i<=15; i++)//右对角线
    {
        if (flag)
        {
            break;
        }
        for (j=19; j>4; j--)
        {
            if (flag)
            {
                break;
            }
            else if (!flag && a[i][j]!=0)
            {
                for (k=1; k<4; k++)
                {
                    if (a[i][j]!=a[i+k][j-k])
                    {
                        break;
                    }
                    if (a[i][j]==a[i+k][j-k] && k!=3)
                    {
                        continue;
                    }
                    if ((k==3&&a[i-1][j+1]==0) || (k==3&&a[i+4][j-4]==0))
                    {
                        printf("%d:%d,%d\n",a[i][j],i+1,j+1);
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    if (!flag)
    {
        printf("No\n");
    }
    return 0;
}
