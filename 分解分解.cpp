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
int a[35];
int main()
{
	int n,k,z,m,i=0;
	scanf("%d%d",&n,&k);
	m=n;
	while(n!=0){
		a[i]=n%k;
		n=n/k;
		i++;
	}
	printf("%d=",m);
	z=i-1;
	while(z>=0){
		if(a[z]>0){
			printf("%d*%d^%d",a[z],k,z);
		m=m-a[z]*(pow(k,z))	;
		z--;
		if(m==0)break;
		printf("+");
		}
	else
	z--;
	}
	return 0;
}