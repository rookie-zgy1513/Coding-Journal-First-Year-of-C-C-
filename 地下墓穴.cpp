#include<stdio.h>
const int  N=1000000007 ;
long long int M[105]={0};
int main()
{
	int n,i;
	scanf("%d",&n);
	M[1]=M[2]=M[3]=1;
	for(i=4;i<=100;i++){
		M[i]=M[i-1]%N+M[i-2]%N+M[i-3]%N;
	}
	printf("%lld",M[n]%N);
	return 0;
}


