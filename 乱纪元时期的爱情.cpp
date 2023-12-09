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
int cmp(const void*c,const void*d){
	return *(int *)c - *(int *)d;
}
int a[1000010],b[1000010]={0};
int main()
{
	int n,k,cnt=0,i,p;
	long long sum=0;
	scanf("%d%d",&n,&k);
	F(i,0,n-1){
		scanf("%d",&a[i]);
		p=a[i];b[p]++;
		if(b[p]!=1){
		a[i]=-1;cnt++;b[p]--;
		}
		
		}
	if(n-cnt<k)
	printf("not find QAQ");
	else{
		qsort(a,n,sizeof(int),cmp);
		for(i=1;i<=k;i++){
			sum=sum+a[n-i];
		}
		printf("%lld\n",sum);
		for(i=n-k;i<=n-1;i++)
		printf("%d ",a[i]);
	}
	return 0;
}