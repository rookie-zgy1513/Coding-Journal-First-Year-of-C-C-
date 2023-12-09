#include<stdio.h>
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int myPOW(int a, int b){
    int ans=1,i;   
	if(a==1)
	ans=1;  
	else 
	for(i=1;i<=b;i++){
		ans=ans*a;
	}   
    //statement
    return ans;
}
int main()
{
	int a,b,c,d;
	while(scanf("%d%d",&a,&b)!=EOF){
		c=MAX(myPOW(a,b),myPOW(b,a));
		d=MIN(myPOW(a,b),myPOW(b,a));
		printf("%d\n",c-d);
	}
	return 0;
}