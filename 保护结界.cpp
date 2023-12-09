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
int cmp1(const void*c,const void*d){
	return ((int*)c)[0]-((int*)d)[0];
}
int cmp2(const void*c,const void*d){
	return ((int*)c)[1]-((int*)d)[1];
}
int cmp3(const void*c,const void*d){
	return ((int*)c)[2]-((int*)d)[2];
}
int x[100005][3];
int main()
{
	long long sum=0,min,sum1=0;
	int n;
	scanf("%d",&n);
	F(i,0,n-1){
		scanf("%d%d%d",&x[i][0],&x[i][1],&x[i][2]);
	}
	qsort(x,n,3*sizeof(int),cmp1);
	if(n%2==1){
		F(i,0,n-1){
			sum=sum+abs(x[i][0]-x[n/2][0]);
		}
		min=sum;
	}
	else{
		F(i,0,n-1){
			sum=sum+abs(x[i][0]-x[n/2][0]);
		}
		min=sum;
		sum=0;
		F(i,0,n-1){
			sum=sum+abs(x[i][0]-x[n/2+1][0]);
		}
		if(sum<min)
		min=sum;
	}
	sum1=sum1+min;
	sum=0;
	qsort(x,n,3*sizeof(int),cmp2);
	if(n%2==1){
		F(i,0,n-1){
			sum=sum+abs(x[i][1]-x[n/2][1]);
		}
		min=sum;
	}
	else{
		F(i,0,n-1){
			sum=sum+abs(x[i][1]-x[n/2][1]);
		}
		min=sum;
		sum=0;
		F(i,0,n-1){
			sum=sum+abs(x[i][1]-x[n/2+1][1]);
		}
		if(sum<min)
		min=sum;
	}
	sum1=sum1+min;
	sum=0;
	qsort(x,n,3*sizeof(int),cmp3);
	if(n%2==1){
		F(i,0,n-1){
			sum=sum+abs(x[i][2]-x[n/2][2]);
		}
		min=sum;
	}
	else{
		F(i,0,n-1){
			sum=sum+abs(x[i][2]-x[n/2][2]);
		}
		min=sum;
		sum=0;
		F(i,0,n-1){
			sum=sum+abs(x[i][2]-x[n/2+1][2]);
		}
		if(sum<min)
		min=sum;
	}
	sum1=sum1+min;
	printf("%lld",sum1);
	return 0;
}