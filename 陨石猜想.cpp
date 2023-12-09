#include <stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    while(x>=10){
    	if(x%4==0)
    	x=x/2;
    	else
    	x=x+x%10+2;
    	printf("%d\n",x);
	}
    printf("End");
    return 0;
}