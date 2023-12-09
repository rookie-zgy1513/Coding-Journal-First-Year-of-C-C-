#include<stdio.h>
int main()
{
	int l,r,n;
	scanf("%o%o",&l,&r);
	if(l%7==0)
	n=r/7-l/7+1;
	else
	n=r/7-l/7;
    printf("%o",n);
	return 0;
}