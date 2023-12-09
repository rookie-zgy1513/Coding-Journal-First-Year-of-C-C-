#include <stdio.h>

int main()
{
	int a,b;
double x[5],y[5];
for(int i=1;i<=4;i++){
	scanf("%d%d", &a, &b);
	x[i]=a;y[i]=b;
}


printf("%.1lf %.1lf\n",(x[1]+x[2]+x[3])/3,(y[1]+y[2]+y[3])/3);
printf("%.1lf %.1lf\n",(x[1]+x[2]+x[4])/3,(y[1]+y[2]+y[4])/3);
printf("%.1lf %.1lf\n",(x[1]+x[4]+x[3])/3,(y[1]+y[4]+y[3])/3);
printf("%.1lf %.1lf\n",(x[3]+x[2]+x[4])/3,(y[3]+y[2]+y[4])/3);

return 0;
}
