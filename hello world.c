#include<stdio.h>
int main()
{
int n, i;
scanf("%d", &n);

printf(" ");
for(i=1;i<=n-2;i++){
	printf("*");
}
printf("\n");//第一行输出结束
for(i=1;i<=n;i++){
	printf("*");
}
printf("\n");


//第二行输出结束
printf(" ");
for(i=1;i<=n-2;i++){
	printf("*");
}
printf("\n");//第三行输出结束
return 0;
}
   












