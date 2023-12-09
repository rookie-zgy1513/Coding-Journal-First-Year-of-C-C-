#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int i=(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
#define MAXNUMBER 105
int num[MAXNUMBER];
int count = 0;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int a[],int n)
{
    int i = 0;
    int j = 0;
    count = 0;
    int flag;//当顺序已经排正确时就不用再继续排序了，可通过flag变量跳出循环
    F(i,0,n-1)
    {
        flag = 0;//每次循环前都给flag赋值为0
        F(j,0,n-i-2)
        {
            count++;
            if (a[j]>a[j+1])
            {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        if (!flag)//当flag为1时代表没进行if判断，代表顺序已经是正确的
            break;
    }
}
void select_sort(int arr[], int n)
{
	//保存参与单趟排序的第一个数和最后一个数的下标
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//保存最大值的下标
		int maxi = begin;
		//保存最小值的下标
		int mini = begin;
		//找出最大值和最小值的下标
		for (int i = begin; i <= end; ++i)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		//最小值放在序列开头
		swap(&arr[mini], &arr[begin]);
		//防止最大的数在begin位置被换走
		if (begin == maxi)
		{
			maxi = mini;
		}
		//最大值放在序列结尾
		swap(&arr[maxi], &arr[end]);
		++begin;
		--end;
	}
}
void adjust(int a[], int i, int n)
{
    int j;
    int temp;
    temp = a[i];
    j = 2*i+1;//左子树
    while (j<n)
    {
        count++;
        if (j<n-1&&a[j]<a[j+1])
            j++;
        if (temp>=a[j])
            break;
        a[(j-1)/2] = a[j];
        j = j*2+1;
    }
    a[(j-1)/2] = temp;
}
void heap_sort(int a[],int n)
{
    int i = 0;
    count = 0;
    for (i=n/2-1; i>=0; i--)
        adjust(a, i, n);
    for (i=n-1; i>=1; i--)
    {
        swap(&a[0], &a[i]);
        adjust(a, 0, i);//交换堆顶的第一个元素与最后那个元素的位置
    }
}


int main()
{
	int n,op;
	scanf("%d %d",&n,&op);
    int i = 0;
    F(i,0,n-1)
    scanf("%d",&num[i]);
	switch (op)
    {
        case 1:
            select_sort(num, n);
            break;
        case 2:
            bubble_sort(num, n);
            break;
        case 3:
            heap_sort(num, n);
            break;
        case 4:
            merge_sort(num, n);
            break;
        case 5:
            quick_sort(num, n);
            break;
    }
	F(i,0,n-1)
    printf("%d ",num[i]);
    printf("\n%d\n",count);
    return 0;
}