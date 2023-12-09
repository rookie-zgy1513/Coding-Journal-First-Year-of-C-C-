#include<stdio.h>
int main()
{
	long long a,b,c,first=0,second=-1;
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		c=a*b;
		if(c>first){
		second=first;
		first=c;
		}
		else if(c>second){
			second=c;
		}
		
	}
	printf("%lld %lld",first,second);
	return 0;
	
	
	
	
}