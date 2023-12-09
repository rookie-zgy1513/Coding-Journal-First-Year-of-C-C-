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
double a[25][5]={0},b[25][4]={0};
double sqr(double x) {
return x*x;
}
double getDis(int m,int i, int j) {
double D = sqrt(sqr(a[m][i]-a[m][j])+sqr(b[m][i]-b[m][j]));
return D;
}
double dot(int m,int i,int j,int n,int k)
{
	double d=((a[m][i]-a[m][j])*(a[m][n]-a[m][k]))+((b[m][i]-b[m][j])*(b[m][n]-b[m][k]));
	return d;
}
int main()
{
	int t;
	scanf("%d",&t);
	F(i,1,t){
		F(j,1,4)
		scanf("%lf%lf",&a[i][j],&b[i][j]);
		if(fabs(a[i][1]+a[i][3]-a[i][2]-a[i][4])<eps&&fabs(b[i][1]+b[i][3]-b[i][2]-b[i][4])<eps){
			if(fabs(getDis(i,1,3)-getDis(i,2,4))<eps&&fabs(dot(i,1,3,2,4))<eps)
			printf("Square\n");
			else if(fabs(getDis(i,1,3)-getDis(i,2,4))<eps)
			printf("Rectangle\n");
			else if(fabs(dot(i,1,3,2,4))<eps)
			printf("Rhombus\n");
			else 
			printf("Parallelogram\n");
		}
		else 
		printf("A normal train trip\n");
	}
	return 0;
}