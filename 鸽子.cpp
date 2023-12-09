#include<stdio.h>
int main()
{
    int num;
	long long int first,second,last,t; 
	last=6000000,first=second=0;
	while(t!=-1)
	{
		scanf("%lld",&t);
		if(t==-1)break;
		if(t>first) 
		{
			second=first; 
			first=t;
		}
		else if(t>second)
		second=t;
		if(t<=last){
			last=t;
		}
		
	}
	if(last==0){
			printf("oh O!");
		}
		else{
			num=(first+second)/last;
			printf("%d",num);
		}

	return 0;
}