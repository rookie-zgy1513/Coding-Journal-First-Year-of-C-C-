#include<stdio.h>
int s[1010]={0},w[1010]={0};
void bubblesort(int a[],int b[],int n)
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
                t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
                flag = 1;
            }
            else if(a[j]==a[j+1]){
            	if (b[j]<b[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
                flag = 1;
            }
			}
        }
        if (flag == 0)//当flag为1时代表没进行if判断，代表顺序已经是正确的
            break;
    }
}
int main()
{
	int n,m,i,count =0;
	scanf("%d",&n);
	for(m=0;m<n;m++){
		scanf("%d%d",&s[m],&w[m]);
	}
	bubblesort(s,w,n);
	for(i=1;i<=n;i++){
		if(i>=2&&s[i-2]==s[i-1]&&w[i-2]==w[i-1]){
			count++;
		printf("%d %d %d\n",i-count,s[i-1],w[i-1]);
		}
		else{
			count=0;
			printf("%d %d %d\n",i-count,s[i-1],w[i-1]);
		}
	}
	return 0;
}