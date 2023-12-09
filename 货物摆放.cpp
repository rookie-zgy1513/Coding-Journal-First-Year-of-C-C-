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
long long sum=0;//const long long N=2021041820210418;//
void count(long long a,int m){
  if(m==1){sum++;return;}
    long long i=1;
    for(i=1;i<=a;i++){
      if(a%i!=0)continue;
      count(a/i,m-1);
    }
}
int main(int argc, char *argv[])
{
  count(4,3);
  printf("%lld",sum);
  // 请在此输入您的代码
  return 0;
}