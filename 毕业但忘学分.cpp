#include<stdio.h>
#include<math.h>
double w[55]={0.0};
int x[55]={0};
double gpa(double x){
	double ans;
	ans=4-3*(100-x)*(100-x)/1600;
	return ans;
}
int main()
{
	int n,i;
	double s;
	double m,c,re,g=0.0,score,sum=0.0;
	double r=100.0,l=60.0;
	scanf("%d%lf%lf",&n,&m,&s);
	for(i=1;i<=n-1;i++){
		scanf("%lf%d",&w[i],&x[i]);
		sum+=w[i];
	}	
	for(re=s-sum;!(re>6.0);re=re+0.5){
		g=0.0;r=100.0;l=60.0;
		for(i=1;i<=n;i++){
			c=x[i];
			g+=gpa(c)*w[i]/(re+sum);
		}
		if(gpa(60.0)*re/(re+sum)>m-g)continue;
		else{
		while(fabs(r-l)>1e-6){
		 if(gpa((l+r)/2)*re/(re+sum)>m-g){
			r=(r+l)/2;
		}
		else if(gpa((l+r)/2)*re/(re+sum)<m-g){
			l=(r+l)/2;
				}
			}
		}	
			score=r;
		printf("%.1lf %.3lf\n",re,score);
	}
		return 0;
}