#include<stdio.h>
#include<math.h>
int s1,s2;
double s(int a,int b,int c,int d,double x) 
{
	double ans=s1*sqrt((a-x)*(a-x)+b*b)+s2*sqrt((c-x)*(c-x)+d*d);
	return ans;
}
int main()
{
	int x1,x2,y1,y2;
	double mid1,mid2,l,r;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d",&s1,&s2);
	l=x1;
	r=x2;
	mid1 = (2*l+r)/3;
	mid2 = (l+2*r)/3;
	while(r-l>1e-6) {
    if(s(x1,y1,x2,y2,mid1) > s(x1,y1,x2,y2,mid2)) {
    	l=mid1;//此时供水站只可能在区间[mid1, r]上
        //补全你的代码
    }
    else {
    	r=mid2;//此时供水站只可能在区间[l, mid2]上
        //补全你的代码
    }
    mid1 = (2*l+r)/3;
    mid2 = (l+2*r)/3;
}
	printf("%.3lf %.3lf",r,s(x1,y1,x2,y2,r));
	return 0;
}