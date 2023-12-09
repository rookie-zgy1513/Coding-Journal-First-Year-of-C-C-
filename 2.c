#include<stdio.h>
int main()
{
	int n,i,m;
	long long s;
	long long int first,second,t;//用于超大型数据 
	first=second=0;//将最大第二大初值为0 
	/*while(t!=-1)
	{
		scanf("%lld",&t);
		if(t>first) 
		{
			second=first; //将旧的最大值给第二大 
			first=t;//更新最大值 
		}
		else if(t>second)//输入的数大于第二大 但小于最大值 
		second=t;//更新 第二大 
		
	}*/
	scanf("%lld",&s);
	for(i=63;i>=0;i--){
		printf("%lld",(s>>i)&1);
	}
	//printf("%ld %ld\n",first,second);
	return 0;
	
}