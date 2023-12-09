#include<stdio.h>
#include<math.h>
int main()
{
	long long int a[101],b[101],c[101],q=0,p[101],m;
	int n,i=1,e=1;
	scanf("%d",&n);
	while(i<=n){
		m=0;
		q=0;
		scanf("%lld%lld",&a[i],&b[i]);
		while(m<=31){
			p[m]=(a[i]%2-b[i]%2)*(a[i]%2-b[i]%2);
			a[i]=a[i]/2; b[i]=b[i]/2;
			q=q+p[m];
			c[i]=q;
			
			m++;
		}
		i++;
		
		
		
		
	}
	while(e<=n){
		printf("%lld\n",c[e]);
		e++;
	}
	return 0;
}