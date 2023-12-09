#include<stdio.h>
int main()
{
	unsigned int a,ans;
	scanf("%u",&a);
	ans=((a&0xffff0000)>>16)|((a&0x0000ffff)<<16);
	printf("%u",ans);
	return 0;
}