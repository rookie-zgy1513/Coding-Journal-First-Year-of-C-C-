#include<stdio.h>
#include<math.h>
int a[10010]={0},b[10010]={0},n,i,c,m;
long long int sum=0,ans=0;
long long int f(int x){
	c=x;
	for(i=1;i<=n;i++){
		sum+=abs(b[c]+b[i]);
	}
	return sum;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]-500;
	}
	for(m=1;m<=n;m++){
		f(m);
	}
	for(i=1;i<=n;i++){
		ans+=2*abs(b[i]);
	}
	printf("%lld",ans+(sum-ans)/2);
	return 0;
}