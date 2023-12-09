#include<stdio.h>
int a[25],b[25];
long long int gcd(long long m,long long n);
int main()
{
	int n,i;
	a[0]=0;b[0]=1;
	long long x=0,y=1,c;
	char ch;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d/%d",&a[i],&b[i]);
		for(i=1;i<n;i++){
			x=a[i]*(b[i+1]/gcd(b[i],b[i+1]))+a[i+1]*(b[i]/gcd(b[i],b[i+1]));
			y=(b[i]*b[i+1]/gcd(b[i],b[i+1]));
			a[i+1]=x/gcd(x,y);
			b[i+1]=y/gcd(x,y);
		}
	if(b[n]==1)
	printf("%lld",a[n]);
	else
	printf("%lld/%lld",a[n],b[n]);
	return 0;
}


long long int gcd(long long int m, long long int n) {// 返回a和b的最大公因数
	while (n != 0) {
	long long int tmp = m;
            	m= n;
		n = tmp % n;
	}
	return m;
}