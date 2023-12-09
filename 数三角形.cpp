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
int n;
int main()
{
	long long cnt=0,cnt1=0,sum;
	
	while(scanf("%d",&n)!=EOF){
		cnt=0;cnt1=0;
		F(i,1,n){
			F(j,1,n){
				if(j==i)continue;
				F(t,1,n){
					if(t==i||t==j)continue;
					if(MIN(abs(t-i),n-(abs(t-i)))==MIN(abs(j-i),n-(abs(j-i)))){
					cnt++;
					if(MIN(abs(t-i),n-(abs(t-i)))==MIN(abs(t-j),n-(abs(t-j))))
					cnt1++;
					}
					
				}
			}
			
		}
		sum=((cnt-cnt1)+cnt1/3)/2;
		printf("%lld\n",sum);
	}
	return 0;
}