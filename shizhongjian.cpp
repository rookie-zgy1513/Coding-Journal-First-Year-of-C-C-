#include<stdio.h>
int main()
{
	int a[1000],b[1000];
	int c,i,e,f;
	i=1;
	
	while(scanf("%d",&a[i])!=EOF,scanf("%d",&b[i])){
		i++;
		
	}
	c=i;
    i=1;
    while(i<=c){
    	if(2*a[i]+b[i]==0)break;
		if(2*a[i]+b[i]+2*a[i+1]+b[i+1]==3)break;
		i++;
	}
	if(i==c){
		printf("%d",c);}
		else 
        printf("%d",i);

  
	
		return 0;
}