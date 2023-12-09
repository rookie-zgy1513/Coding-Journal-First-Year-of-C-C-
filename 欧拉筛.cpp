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
#include<stdio.h>
int prime[1010];//存放素数 
bool vis[1000000];//检验素数，vis[i]=0代表i是素数, vis[i]=1代表i不是素数 
int main()
{
	int t=0;//1是为了让p[1010]这个数组连续存放素数，自己定义的下标（不用i；
			//2是为了记录素数个数，为后来的循环做条件。 
	for(int i=2;i<=1000;i++)//这里定义的i，既是素数的来源（第13行），也是后面（第20行）用来筛合数的乘数 
	{
		//printf("##i=%d\n",i);
		if(vis[i]==0)//如果是i是素数 
		{
			prime[t]=i;//保存在p[]里 
			t++;
		}
		//printf("t=%d ",t-1);
		for(int j=0;j<t;j++)//开始筛 
		{
			//printf("##i=%d prime[j]=%d i*prime[j]=%d\n",i,prime[j],i*prime[j]);
			vis[prime[j]*i]=true;//把合数筛掉 
			if(i%prime[j]==0)//这里就是埃氏筛和欧拉筛不同之处，优化大多就靠这一条语句（后有证明 
				break;
		}
		//printf("\n------------\n");
	}
	for(int i=0;prime[i]!=0;i++)//输出素数 
		printf("%d  ",prime[i]);
}
