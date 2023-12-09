#include<stdio.h>
int main()
{
	int T,n[1000];
	int i=0;
	scanf("%d",&T);
	while(i<T){
		scanf("%d",&n[i]);
		i++;
		}
		i=0;
		while(i<T){
			if(n[i]%2==0)
				printf("Yes\n");
			else
			printf("No\n");
			i++;
		}
		return 0;
}