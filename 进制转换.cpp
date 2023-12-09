#include<stdio.h>
int main()
{
	char ch;
	int a,i=0,temp[1001]={0},n=1,m=1;
	while(scanf("%c",&ch)!=EOF){
		if(ch=='a')
		temp[m]=10;
		else if(ch=='b')
		temp[m]=11;
		else if(ch=='c')
		temp[m]=12;
		else if(ch=='d')
		temp[m]=13;
		else if(ch=='e')
		temp[m]=14;
		else if(ch=='f')
		temp[m]=15;
		else
		temp[m]=ch;
		
		i++;
		m++;
	}
	while(n<=i){
		printf("%d%d%d%d",((temp[n]>>3)&1),((temp[n]>>2)&1),((temp[n]>>1)&1),((temp[n]>>0)&1));
		n++;
	}
	return 0;
}