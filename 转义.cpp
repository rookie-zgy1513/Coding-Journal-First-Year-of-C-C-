#include<stdio.h>
int main()
{
	char ch;
	scanf(" %c",&ch);
	switch(ch){
		case 'a':
			printf("\a");break;
		case 'b':
			printf("\b");break;
		case 'f':
			printf("\f");break;
		case 'n':
			printf("\n");break;
		case 'r':
			printf("\r");break;
		case 't':
			printf("\t");break;
		case 'v':
			printf("\v");break;
		case '0':
			printf("\0");break;
		default :
			printf("%c",ch);break;
	}
	return 0;
}