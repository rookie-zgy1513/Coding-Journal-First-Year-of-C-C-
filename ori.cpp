#include<stdio.h>
int b[110];
void bubblesort(int a[],int n)
{
    int i = 0;
    int j = 0;
    int t = 0;
    int flag;//当顺序已经排正确时就不用再继续排序了，可通过flag变量跳出循环
    for (i=0; i<n; i++)
    {
        flag = 0;//每次循环前都给flag赋值为0
        for (j=0; j<n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag = 1;
            }
        }
        if (flag == 0)//当flag为1时代表没进行if判断，代表顺序已经是正确的
            break;
    }
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	bubblesort(b, n);
	for(i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	while(n-1>=0){
		printf("%d ",b[n-1]);
		n--;
	}
	return 0;
}