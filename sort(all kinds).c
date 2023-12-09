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
void select_sort(int a[], int n)
{
    int i = 0;
    int j = 0;
    int min = 0;
    count = 0;
    F(i,0,n-1)
    {
        min = i;
        F(j,i+1,n-1)
        {
            count++;
            if (a[j]<a[min])
                min = j;
        }
        if (i!=min)
            swap(&a[i], &a[min]);
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
void QUICK(int key[], int s, int t)
{
    int i = 0;
    int mid = 0;
    if(s<t)
    {
        mid = s;
        for(i=s+1;i<=t;i++)
        {
            count++;
            if(key[i]<key[s])
                swap(&key[++mid],&key[i]);
        }
        swap(&key[s],&key[mid]);
        QUICK(key,s,mid-1);
        QUICK(key,mid+1,t);
    }
}
void quick_sort(int key[], int n)
{
    QUICK(key, 0, n-1);
}
void MERGE(int x[], int z[], int s, int u, int v)//合并小序列
{
    //将有序序列x[s...u],x[u+1...v]合并为有序序列x[s...v]
    int i,j,q;
    i = s;
    j = u+1;
    q = s;
    while (i<=u&&j<=v)
    {
        count++;
        if (x[i]<=x[j])
            z[q++] = x[i++];
        else
            z[q++] = x[j++];
    }
    while (i<=u)
        z[q++] = x[i++];
    while (j<=v)
        z[q++] = x[j++];
    for (i=s; i<=v; i++)
    {
        x[i] = z[i];
    }
}
void MPASS(int x[], int y[], int n, int t)
{
    int mid;
    if (n<t)
    {
        mid = (n+t)/2;
        MPASS(x, y, n, mid);
        MPASS(x, y, mid+1, t);
        MERGE(x, y, n, mid, t);
    }
}
void merge_sort(int x[], int n)
{
    int *p;
    p = (int *)malloc(sizeof(int)*n);
    if (p!=NULL)
        MPASS(x, p, 0, n-1);
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