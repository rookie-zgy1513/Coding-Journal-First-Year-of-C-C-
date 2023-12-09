#include <stdio.h>
#include <math.h>
int getFac(int n)
{   int i;
    long long ans=1;
 for(i=1;i<=n;i++)
 {
 ans*=i; 
 }
 return ans;
}
int main()
{
 int k,m,a;
 double Ans=1.000000;
 scanf("%d%d",&k,&m);
 for(a=1;a<=m;a++)
 {
  	Ans+=(double)pow(k,a)/getFac(a); 
 }
 printf("%.6lf",Ans);
 return 0;
}