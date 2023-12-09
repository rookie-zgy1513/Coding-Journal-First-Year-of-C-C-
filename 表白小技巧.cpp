#include<stdio.h>
char s[50];
int main()
{
	int n,j=1;
	long long int a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		j=1;
		if(a){
		while(a){
			s[j]=(a%26)+'a';
			j++;
			a=a/26;
		}
		j--;
		while(j>=1){
			printf("%c",s[j]);
			j--;
		}
	}
	else
	printf("a");
		
		printf(" ");
	}
	return 0;
	
}