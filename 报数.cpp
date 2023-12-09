#include <stdio.h>
int main()
{
 int a[80],m,n,i,k,j;//设置最多80人
 printf ("Enter n:");//输入人数
 scanf ("%d",&n);
 printf ("Enter m:");//输入数字
 scanf ("%d",&m);
 for (i=0;i<n;i++)   // 初始化为1
 {
  a[i]=1;            //a[i]=1代表游戏中
 }
 k=n;               //k代表人数
 j=0;               //初始化j
 i=0;               //重置i为0
 while (k>1)        //当人数大于1时循环
 {
  if (a[i]!=0)j++; //当没出局时，j计数
  if (j==m)
  {
   j=0;            //重置j
   a[i]=0;         //a[i]=0代表出局
   k--;
   printf ("%d出局！\n",i+1);
  }
  i++;
  if (i==n)i=0;   //i到达数组尾，重置为数组头
 }
 for (i=0;i<n;i++)
 {
  if (a[i]==1)
  {
   printf ("%d号胜利！\n",i+1);
  }
 }
 return 0;
}
