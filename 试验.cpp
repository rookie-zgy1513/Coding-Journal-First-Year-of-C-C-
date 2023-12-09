#include<stdio.h>
int main()
{
	int num;
	char ch;
	scanf("%c",&ch);
	 if('0' <= ch && ch <= '9'){
        num = ch- '0';
        printf("%d",num);
    }
    return 0;
	
}