#include <stdio.h>
int main()
{
        int n,m;
        
        scanf("%d%d",&n,&m);
        int a[1000];
        int i,temp;
        int count=0;
        temp=n;
        for(i=0;i<n;i++)
        {
          a[i] = i+1;
        }
        i=0;
        while (n>1)
        {
             if(a[i]!=0)   //不改变第一次报数值，只是让数字3的人为0
             {
                 count++;
             }
             if(count== m)
             {
                    a[i]=0;  //让数到3的人为0
                    count=0;
                    n--;  //人数－1
             }
             i++;
             if(i==temp)
             {
                    i = 0;
             }
        }
        for(i=0;i<temp;i++)
        {
                if(a[i]!= 0)  //此时所有数到3的人都清零了，只有剩下的那一个不为0
                {
                        printf("%d\n",a[i]);//余下的是
                }
        }
        return 0;
}
