#include<stdio.h>
int main()
{
	int a,b,op,c;
	scanf("%d%d%d",&a,&b,&op);
	if(op==0){
		
	c=a+b;
	printf("%d + %d = %d\n",a,b,c);
	}
	if(op==1){
	
	c=a-b;
	printf("%d - %d = %d\n",a,b,c);
	}

    if (op==2){
    
	c=a*b;
	printf("%d * %d = %d\n",a,b,c);
	}
	if(op==3){
    if(b==0)
    printf("error");
	if(b!=0)
	c=a/b;
	printf("%d / %d = %d",a,b,c);	
		
	}
	

    return 0;
}