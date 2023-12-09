#include<stdio.h>
int main()
{
	int a[1000],b[1000];
	int c,i,e,f;
	e=i=1;
	while(scanf("%d",&a[i])!=EOF){
			scanf("%d",&b[i]);
		i++;
		
	}
	c=i;
    while(e<c){
    	if(2*a[e+1]+b[e+1]==0)break;
    	else if(2*a[e]+b[e]+2*a[e+1]+b[e+1]==3)break;
    	e++;
	}
	if(e==c){
		printf("%d",c);
		}
		else 
        printf("%d",e);
    
        return 0;
}