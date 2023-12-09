#include<stdio.h>
#include<string.h>	

int main()
{
    int i=0,n=1;
    char str[10000];
	scanf("%[^\n]",str);
	n=strlen(str);
	for(i=0;i<n;i++){
		
	if(str[i]==' ')
		printf("  ");
	else
		printf("%c",str[i]);
	}
	return 0;
	
	
	
}