#include<stdio.h>
int main()
{
	int m,t,s,n;
	scanf("%d%d%d",&m,&t,&s);
	if(t==0){
		n=0;
		printf("%d",n);
	}
	else{
		if(s%t==0){
			if(m*t-s<=0){
			n=0;
			printf("%d",n);
			}
			
			else{
			n=m-s/t;
			printf("%d",n);
			}
			
		}
		else{
		if(m-s/t<=1){
		n=0;
		printf("%d",n);
		}
		else{
		n=m-s/t-1;
		printf("%d",n);
		}
				
		}
	}
	return 0;
}