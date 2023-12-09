#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int main()
{
	long long int mm=10000000000;
	int n,a,b,i=1,m;
	double sum=0,aver;
	scanf("%d",&n);
	while(i<=n){
		scanf("%d%d",&a,&b);
		m=MAX(abs(a),abs(b));
		if(m<mm)
		mm=m;
		sum=sum+m;
		if(m==0)
		printf("Perfect\n");
		else if(m>0&&m<=3)
		printf("Excellent\n");
		else if(m>3&&m<=5)
		printf("Good\n");
		else if(m>5&&m<=10)
		printf("Not Bad\n");
		else if(m>10)
		printf("Oh!\n");
		i++;
		}
	aver=sum/n;
	printf("%lld %.2lf",mm,aver);
	return 0;
}