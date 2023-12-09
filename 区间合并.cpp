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
int a[1000010][2],b[1000010];
int cmp(const void*c, const void*d){
      return((int*)c)[0]-((int*)d)[0];//这里[]下标换成你自己的排序依据
}
int main()
{
	int i=0,j=0,n,cnt,flag,t;
	while(scanf("%d%d",&a[i][0],&a[i][1])!=EOF){
		i++;
	}
	n=i;cnt=n;
	qsort(a,n,2*sizeof(int),cmp);
	for(i=1;i<n;i++){
		if(a[i][0]<=a[i-1][1]&&a[i][0]>=a[i-1][0]){
			if((a[i][0]<=a[i-1][1]&&a[i][0]>=a[i-1][0])&&(a[i][1]<=a[i-1][1]&&a[i][1]>=a[i-1][0])){
				a[i][0]=a[i-1][0];a[i][1]=a[i-1][1];
				a[i-1][0]=0;a[i-1][1]=0;
			}
			else {
				a[i][0]=a[i-1][0];
				a[i-1][0]=0;a[i-1][1]=0;
			}
		}
	}
	for(i=0;i<n;i++){
		if(a[i][0]==0&&a[i][1]==0)continue;
		printf("%d %d\n",a[i][0],a[i][1]);
	}
	return 0;
}