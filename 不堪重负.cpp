#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int main()
{
	int m,n,i,a,b;
	long long s1=0,s2=0,ans;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++){
		scanf("%d",&a);
		s1=s1+a;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b);
		s2=s2+b;
	}
	printf("%lld",s1*s2);
	return 0;
}