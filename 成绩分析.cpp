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
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);//由小到大排序
     //return *(int *)b - *(int *)a; 由大到小排序
}
int a[510]={0};
int main()
{
	int min=101,max=-1,n,i=0;
	double sum=0.0,midd,aver;
	while(1)
	{
		i=0;
		if(scanf("%d",&a[i])==EOF)break;
		max=a[i];min=a[i];sum=a[i];i++;
		while(1){
			scanf("%d",&a[i]);
			if(a[i]==-1)break;
			if(a[i]>max)max=a[i];
			if(a[i]<min)min=a[i];
			sum+=a[i];
			i++;
		}
		qsort(a,i,sizeof(a[0]),cmp);
		if(i%2)
		midd=1.0*a[i/2];
		else
		midd=1.0*(a[i/2]+a[i/2-1])/2;
		aver=sum/i;
		printf("%d %d %.2lf %.2lf\n",max,min,aver,midd);
		}
	return 0;
}