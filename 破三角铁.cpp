#include<stdio.h>
int use[5001]={0};
const long long N=1000000007;
int main()
{
	int n,i,x,a,b,c,way=0,max=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		use[x]++;
		if(x>max)
		max=x;
	}
	for(i=2;i<=max;i++){
		if(use[i]>=2){
			if(i%2==0){
				a=i/2;b=i/2;
				if(use[a]>=2)
				ans+=(use[a]*(use[a]-1)/2)%N;a--;b++;
				while(a>=1){
					ans+=(use[a]*use[b])/2%N;
					a--;b++;
				}
			}
			else{
				a=i/2;b=i/2+1;
				while(a>=1){
					ans+=(use[a]*use[b])/2%N;
					a--;b++;
				}
			}
		}
		way=way+ans;
	}
	way=way%N;
	printf("%d",way);
	return 0;
}
