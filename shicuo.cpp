/*#include<stdio.h>
int main()
{
	int t,i=2,x,m=1,a[11]={0},b[11]={0};
	int n,c=1,prime[10001]={0};
	while(i<=10000){
		for(x=2;x<10000;x++){
			if(i%x==0)break;
		}
		if(x>=i)
		prime[i]=i;
		i++;
	}
	prime[2]=2;
	scanf("%d",&t);
	while(m<=t){
	scanf("%d",&n);
	
	i=2;
		while(i<=5000){
			if(prime[i]!=0){
				if(prime[n-i]!=0)break;
			}
			i++;
		}
		a[m]=prime[i];
		b[m]=n-prime[i];
		m++;
	}
	m=1;
	while(m<=t){
	printf("%d %d\n",a[m],b[m]);
	m++;
	}
		
	return 0;
}*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void Exgcd(int a,int b,int *d,int *x,int *y)
{
	int m=0;
    if(b==0)
    {
     *d=a;
     *x=1;
     *y=0;
     Exgcd(b,a%b,d,y,x);
 }
 else
 {
 	int n,p;
 	n=*x;
 	p=*y;
 	m=n-p*(b/a);
 	*x=m;
  Exgcd(b,a%b,d,y,x);
 }
}
int main()
{
 int d=0,x=0,y=0,a,b;
 scanf("%d%d",&a,&b);
 Exgcd(a,b,&d,&x,&y);
 printf("%d = %d*(%d) + %d*(%d)",d,a,x,b,y);
 return 0;
}