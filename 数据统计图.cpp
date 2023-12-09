#include<stdio.h>
#include<ctype.h>
int sum[26]={0};
int main()
{
	char ch;
	int max=0,i,m,n;
	ch=getchar();
	while(ch!=EOF){
		if(islower(ch)){
			sum[ch-97]++;
			if(sum[ch-97]>max)
		max=sum[ch-97];
		}
		else if(isupper(ch)){
			sum[ch-65]++;
			if(sum[ch-65]>max)
		max=sum[ch-65];
		}
		ch=getchar();
	}
	n=max;
	for(i=1;i<=max;i++){
		for(m=0;m<25;m++){
			if(sum[m]==n){
			printf("* ");
			sum[m]--;
			}
			else
			printf("  ");
		}
		if(sum[25]==n){
			printf("*");
			sum[25]--;
			}
			else
			printf(" ");
			printf("\n");
			n--;
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
}