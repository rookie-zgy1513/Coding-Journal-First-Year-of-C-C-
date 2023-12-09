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
long long a[10010],max=0,pro;
int main()
{
	int n,flag=0,b,c;
	while(scanf("%d",&n)!=EOF){
		max=0;
		F(i,1,n){
			scanf("%lld",&a[i]);
			F(j,1,i-1){
				pro=a[i]-a[j];
				if(pro>max){max=pro;
				b=j;c=i;
				}
				
			}
		}
		if(max==0)
		printf("No profit!\n");
		else
		printf("%lld %d %d\n",max,b,c);
	}
	return 0;
}