#include<stdio.h>
int main()
{
	int sum=0;
	char ch;
while (scanf("%c", &ch) != EOF)
{
	sum=sum+ch;
}
   if(sum==107){
   	printf("Goldenglow!");
   }
	else if(sum==314){
		printf("You, you and you");
	}
    else if(sum>=2022){
    	printf("Jellyfish Food");
	}
	else{
		printf("%d",sum);
	}
	return 0;
}