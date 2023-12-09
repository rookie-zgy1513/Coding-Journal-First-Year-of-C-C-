#include<stdio.h>
int n,k,l,a[50],sum = 0;
void func(int ret, int t) {
//ret：剩余元素的数量，t:目前正在处理的组数
if (t == k ) {
if (ret) return; //边界2
//边界3
sum ++;
for (int i = 0; i <= k-1; i++)
printf("%d ", a[i]);
printf("\n");
return ;
}
if (!ret) return ; // 边界1
for (int i = 0; i <=ret; i ++) {
a[t] = i; //保存该组内的元素个数
func(ret - i, t + 1);
}

}

int main()
{
scanf("%d%d%d", &n,&k,&l);
while(k<=l){
 	func(n,0);
 	k++;
 }
printf("%d\n", sum);
return 0;
}