#include<stdio.h>
void f(int x);
int main()
{
	int i,t,n;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		f(n);
		printf("\n");
	}
	return 0;
}

void f(int x)
{
	int a;
	if(x==1||x==0){
		for(a=1;a<=x+1;a++){
			printf("{");
		}
		for(a=1;a<=x+1;a++){
			printf("}");
		}
	}
	else{
		a=0;
		printf("{");
		while(a<=x-1){
			f(a);
			a++;
			if(a==x)break;
			printf(",");
		}
		printf("}");
	}
	
}