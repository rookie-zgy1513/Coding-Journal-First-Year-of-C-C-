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
char s[100];
char s2[100];
int main()
{
	long long re,sum,out1;
	double x,p,in,out;
	int n;
	char c;
	scanf("%d",&n);
	scanf("%s",s);
	sscanf(s,"%lf%s",&x,s2);
	if(s2[0]=='G')
	in=x*pow(10,9);
	else if(s2[0]=='M')
	in=x*pow(10,6);
	else if(s2[0]=='k')
	in=x*pow(10,3);
	else if(s2[0]=='B')
	in=x;
	re=ceil(in);
	F(i,1,n){
		scanf("%s",s);
	sscanf(s,"%lf%s",&x,s2);
	if(s2[0]=='G')
	out=x*pow(10,9);
	else if(s2[0]=='M')
	out=x*pow(10,6);
	else if(s2[0]=='k')
	out=x*pow(10,3);
	else if(s2[0]=='B')
	out=x;
	scanf("%lf",&p);
	out1=ceil(p*out);
	printf("%lf %s\n",x,s2);
	if(re>out1){
	re=re-ceil(out);
	printf("%lld\n",re);
	}
	else
	printf("memory space inadequate\n");
	}
	return 0;
}