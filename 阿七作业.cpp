#include<stdio.h>
#define PI 3.1415926
int main(void)
{
    double de,ra;
	printf("\n请输入一个角度：");
	scanf("%lf",&de);
    ra=(PI/180.0)*de;
	printf("将%f度角转换为弧度是:%lf\n",de,ra);
	return 0;
} 