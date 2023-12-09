#include<stdio.h>
#include<math.h>
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int main()
{
	long long int f[100];
	int a,i,t;
	f[1]=f[2]=1;
	for(i=3;i<=99;i++){
		f[i]=f[i-1]+f[i-2];
	}
	scanf("%d",&a);
	t=f[a]%10;
	printf("%d",t);
	return 0;
}