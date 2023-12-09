#include <stdio.h>
int a[15]={0};//保存数列的数组,默认每个位置都是0
int  book[15]={0};//记录一个数有没有在数组里
int n,m;//1~n
void getORDER(int pos,int x)//向getORDER[pos]填数
{
    if(x==0)//递归边界
    {
        for(int i=1;i<=m;i++)//输出数列
            printf("%d ",a[i]);
        printf("\n");
 		return;
		 }
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0)//如果i没有在数组里面,用以排除掉原本i的位置
        {
            a[pos]=i;
            book[i]=1;
            getORDER(pos+1,x-1);//向getORDER[pos+1]填数
            a[pos]=0;
            book[i]=0;//收回，试下一个数
        }
    }
}
int main()
{
	scanf("%d%d",&n,&m);
    getORDER(1,m);
    return 0;
}