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
void bubblesort(long long int a[],int n)
{
    int i = 0;
    int j = 0;
    int t = 0;
    int flag;//当顺序已经排正确时就不用再继续排序了，可通过flag变量跳出循环
    for (i=0; i<n; i++)
    {
        flag = 0;//每次循环前都给flag赋值为0
        for (j=0; j<n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag = 1;
            }
        }
        if (flag == 0)//当flag为1时代表没进行if判断，代表顺序已经是正确的
            break;
    }
}
long long int a[110];
int main()
{
	int n=0,cnt=0,i;
	long long max=-1;
	while(scanf("%lld",&a[n])!=EOF){
		cnt=0;
		FD(i,0,n){
			if(a[i]==a[n]){
				a[i]=-1;a[n]++;
				cnt++;
			}
		}
		while(cnt>0){
			cnt=0;
		FD(i,0,n){
			if(a[i]==a[n]){
				a[i]=-1;a[n]++;
				cnt++;
			}
		}
	}
	F(i,0,n){
		if(a[i]>max)
		max=a[i];
	}
	printf("%lld\n",max);
	n++;
  }
  bubblesort(a,n);
	for(i=n-1;i>=0;i--){
		if(a[i]==-1)break;
		printf("%lld ",a[i]);
	}
	return 0;
}