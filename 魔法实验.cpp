#include<stdio.h>
int main()
{
	int T,n,a=0,b,d=1,e,f=1,i=1,c=0;
	long long m[100005],o[1000005];
	
	scanf("%d",&T);
	while(i<=T){
		scanf("%d",&n);
		e=b=1;
		while(n>0){
			scanf("%lld",&m[b]);
			if(m[b]%2==1){
			a++;	
			}
		m[b]=m[b]/2;
		b++;
		n--;
		}
		if(a>0){
		o[d]=b-a;	
		}
		else{
			while(a==0){
			while(e<=b){
				if(m[e]%2==1){
					a++;
					}
				m[e]=m[e]/2;
				e++;
			}
			c++;
			}
			o[d]=b+c-1;
		}
		
		i++;
	}
	while(f<=T){
		printf("%lld\n",o[f]);
		b++;
	}
	return 0;
}