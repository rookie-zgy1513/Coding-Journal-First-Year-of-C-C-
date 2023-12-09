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
int a[5010];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
 } 
int main()
{
	int n,x=0,sum=0;
	double aver;
	scanf("%d",&n);
	FD(i,0,n){
		scanf("%d",&a[i]);
		if(a[i]==110)
		x++;
		sum=sum+a[i];
	}
	qsort(a,n,sizeof(int),cmp);
	aver=(sum+0.0)/n;
	FD(i,0,n)
	printf("%d ",a[i]);
	printf("\n");
	printf("%.2lf\n",aver);
	if(x)
	printf("There are %d people who got full marks!",x);
	else
	printf("It's a great pity that no one got a perfect score.");
	return 0;
	
	
	
	
	
	
}