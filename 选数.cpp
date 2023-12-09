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
long long int count,sum;
int a[25],d[25];const int N=100000005;
int prime(int m)
    {
        int i,k;
        if(m==1)
            return 0;
        k=(int)sqrt(m);
        for(i=2;i<=k;i++)
        {
            if(m%i==0)
                return 0;
        }
        return 1;
    }

void process(int e,int b){
	if(!b){
		if(prime(sum)){count++;sum=0;return ;
		}
		else{
			sum=0;return ;
		}	
	}
	F(j,1,e){
		if(d[j]!=0)continue;
		d[j]=1;
		sum=sum+a[j];
		process(e,b-1);
		d[j]=0;
	}
	
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	F(i,1,n)
	scanf("%d",&a[i]);
	process(n,k);
	printf("%lld",count);
	return 0;
}