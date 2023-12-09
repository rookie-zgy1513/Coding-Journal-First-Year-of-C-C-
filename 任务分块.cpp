#include<stdio.h>
#include<math.h>
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
int main()
{
	int a,n,x,t,s;
	long long ans=0,p,q;
	scanf("%d%d",&n,&x);
	for(t=1;t<=n;t++){
		ans=0;
		scanf("%d",&a);
		if(prime(a))
		ans=a;
		else{
			s=sqrt(a);
			for(;s>=0;s--){
				if(a%s==0)break;
			}
			ans=ans+(s+a/s)*(x+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
	
	
	
	
	
	
	
	
