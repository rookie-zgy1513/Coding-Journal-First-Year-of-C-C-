#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int s1[5050],s2[5050];

void bubblesort(int a[],int b[],int n)
{
    int i = 0;
    int j = 0;
    int t = 0;
    int flag;//当顺序已经排正确时就不用再继续排序了，可通过flag变量跳出循环
    for (i=0; i<n; i++)
    {
        flag = 0;//每次循环前都给flag赋值为0
        for (j=0; j<n-i-1;j++)
        {
            if(a[j]+b[j]>a[j+1]+b[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
                flag = 1;
            }
            else if(a[j]+b[j]==a[j+1]+b[j+1]){
            	if (fabs(a[j]-b[j])<=fabs(a[j+1]-b[j+1]))
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
        
    }
}

int main()
{
	int i=0,n;
	while(scanf("%d%d",&s1[i],&s2[i])!=EOF){
		
		i++;
	}
	n=i;
	bubblesort(s1,s2,n);
	for(i=n-1;i>=0;i--){
		printf("%d %d\n",s1[i],s2[i]);
	}
	return 0;
}

