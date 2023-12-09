#include<stdio.h>
#include<ctype.h>
int main()
{
	int a=0,b=0,c=0;
	char ch;
	while(scanf("%c",&ch)!=EOF){
		if(islower(ch) )
		b++;
		else if(isdigit(ch))
		a++;
		else if(isupper(ch))
		c++;
		}
	printf("%d %d %d",a,b,c);
	return 0;
}