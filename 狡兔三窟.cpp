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
int flag[11]={0};
int main()
{
	int pos=0;
	F(i,1,1000){
		pos=pos+i;
		if(pos>10)
		pos=pos%10;
		flag[pos]=1;
	}
	flag[10]=1;
	if(flag[1]+flag[2]+flag[3]+flag[4]+flag[5]+flag[6]+flag[7]+flag[9]+flag[8]+flag[10]==10)
	printf("NIE");
	else
	F(i,1,10){
		if(flag[i]==0)
		printf("%d ",i);
	}
	return 0;
}