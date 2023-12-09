#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,op=0;
	while(scanf("%d",&n)!=EOF){
		op=0;
		if(n==0||n==-1){
			op=-1;
		}
		else if(n==1){
			op==0;
		}
		else{
			while(n!=1&&n!=-1){
				if(abs(n)%2==0){
				n=n/2;
				  op++;
				}
				else if(abs(n)%2==1){
					n=-(n+1);
					op++;
				}
			}
		}
		printf("%d\n",op);
	}
	return 0;
}