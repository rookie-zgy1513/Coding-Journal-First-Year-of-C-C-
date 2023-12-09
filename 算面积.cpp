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
#define pi 3.1415926
int a[1010],b[1010];
double result[5010]={0};
double s,s1;
double sqr(int x) {
return x*x;
}
double getDis(int i, int j) {
double d = sqrt(sqr(a[i]-a[j])+sqr(b[i]-b[j]));
return d;
} 
double calS(double g,double h,double k){
	double p=(g+h+k)/2;
	double ans;
	ans=sqrt(p*(p-g)*(p-h)*(p-k));
	return ans;
}

int judge(int a1,int a2,int b1,int b2,int c1,int c2)
{
	if((a1-b1)*(b2-c2)==(b1-c1)*(a2-b2))
	return 1;
	else
	return 0;
}

int main()
{
	int n,m,op,num1,num2,num3;
	double r;
	char C1,C2,C3;
	scanf("%d",&n);
	F(i,1,n)
	scanf(" %c%d%c%d%c",&C1,&a[i],&C2,&b[i],&C3);
	scanf("%d",&m);
	F(i,1,m){
		scanf("%d%d%d%d",&num1,&num2,&num3,&op);
		if(judge(a[num1],b[num1],a[num2],b[num2],a[num3],b[num3]))
		printf("Yuzuriha Inori\n");
		else{
			switch(op){
				case 1:
				s=	calS(getDis(num1, num2) ,getDis(num1, num3) ,getDis(num2, num3));
				printf("%.3lf\n",s);break;
				case 2:
				s=	calS(getDis(num1, num2) ,getDis(num1, num3) ,getDis(num2, num3) );
				r=  2*s/(getDis(num1, num2) +getDis(num1, num3) +getDis(num2, num3) );
				s1=r*r*pi;
				printf("%.3lf\n",s1);break;
			}
		}
	}
	return 0;
}
