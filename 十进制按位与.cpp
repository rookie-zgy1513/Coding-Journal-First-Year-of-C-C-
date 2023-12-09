#include<stdio.h>
#include<math.h>
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))

int main()
{
	int a,b,c,i=0,d,n,u[11]={0},m=0;
	scanf("%d%d",&a,&b);
	if(a*b==0){
		printf("0");
	}
	
	else{
	c=MAX((log10(a)),(log10(b)));
	d=c;
	while(c>=0){
		u[i]=MIN((a%10),(b%10));
		a=a/10; b=b/10;
		c--;
		i++;
	}
	while(d>=0){
		m=m+u[d]*(pow(10,d));
		d--;
	}
	printf("%d",m);
	}
	
	return 0;
}