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
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}
int n, k,t,j, sum = 0, a[25];
void func(int ret, int t) { //ret：剩余元素的数量，t:目前正在处理的组数
if (t == k + 1) {
if (ret) return; //边界2
//边界3
sum ++;
return ;
}
if(!ret)return;
for (int i = 1; i <= 3; i ++) {
a[t] = i; //保存该组内的元素个数
func(ret - i, t + 1);
	}
}
int main()
{
	scanf("%d",&t);
	for(j=1;j<=t;j++){
		sum=0;
	scanf("%d", &n);
for(k=1;k<=n;k++)
func(n, 1);
printf("%d\n",sum);
}

return 0;}