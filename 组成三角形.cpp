#include<stdio.h>
#include<math.h>
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int main()
{
	int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    
    if(c<a+b&&b<a+c&&a<c+b){
      
	  if(c*c+b*b>a*a&&c*c+a*a>b*b&&a*a+b*b>c*c){
       printf("acute triangle\n");
       if(a==b&&b==c){
       	printf("equilateral triangle");
	   }
	   else if(a==b||b==c||c==a){
	   	printf("isosceles triangle");
	   }
    }
	else if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a){
        printf("right triangle\n");
        if(a==b||b==c||c==a){
	   	printf("isosceles triangle");
	   }
    }
	else{
		printf("obtuse triangle\n");
		if(a==b||b==c||c==a){
	   	printf("isosceles triangle");
        //说明是钝角三角形
    }
    }
    }else{
    	printf("no triangle");
    //说明无法组成三角形
  }
   return 0;	
}