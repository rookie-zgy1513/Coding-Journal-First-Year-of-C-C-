#include <stdio.h>
#include <math.h>
int prime(int m);/*判断是否为质数*/
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;n!=1;i++)
    {
        if(n%i==0)
        {
            if(prime(i)==1)
            {
                if(n!=1)
                {
                    n=n/i;
                    printf("%d ",i);
                    i=1;
                }
                else
                {
                    printf("%d",i);
                }
            }
        }
    }
	 return 0;
}

    int prime(int m)
    {
        int i,k;
        if(m==1)
            return 0;
        k=(int)sqrt(m);
        for(i=2;i<=k;i++)
        {
            if(m%i==0)
                return 0;
        }
        return 1;
    }
