#include <stdio.h>
int main()
{
 int x,y,z;
 scanf("%d",&x);
 if(x%2==1){
 y=(x*x-1)/2;
 z=(x*x+1)/2;
 }
 else if(x%2==0&&x%4!=0){
 	y=(x*x/4-1);
    z=(x*x/4+1);
 }
 else if(x%4==0){
 	y=3*x/4;
 	z=5*x/4;
 }
 printf("%d %d %d",x,y,z);
return 0;
}