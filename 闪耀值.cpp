#include<stdio.h>
#include<math.h>
long long int getFAC(int x,int y);
long long int base(int m,int n);
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%lld %lld\n",base(getFAC(a,c),b),base(getFAC(b,c),a));
	if(fabs(base(getFAC(a,c),b)-base(getFAC(b,c),a))>9)
	printf("Mabushi~");
	return 0;
}

long long int getFAC(int x,int y)
{
	int i=1,ans=1;
	
	while(i<=x){
		ans=ans*(i%y);
		i++;
		ans=ans%y;
	}
	
	return ans;
}
long long int base(int m,int n)
{
	int ANS;
	ANS=m/n;
	return ANS;
}