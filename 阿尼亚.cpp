#include<stdio.h>
#include<string.h>
int main()
{
	int x,a=0;
	char s;
	scanf("%d",&x);
	s=getchar();
	while(s!='c'){
		s=getchar();
		if(s=='n')
		a++;
		else if(s=='d')
		a=a+2;
	}
	printf("%d",a);
	return 0;
}