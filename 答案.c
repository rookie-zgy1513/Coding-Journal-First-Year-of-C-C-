#include<stdio.h>
int a,sum,num;
int main()
{
scanf("%d",&a);
while(a!=0)
{
num++;
sum+=a;
scanf("%d",&a);
}
printf("%d %d %d",sum,num,sum/num);
return 0;
}