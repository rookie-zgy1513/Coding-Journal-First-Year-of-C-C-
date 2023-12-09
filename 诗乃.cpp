#include<stdio.h>
int main()
{
	int n,a[9],i,m=1,sum1,sum2;
	int b[9],c[9]={0};
	scanf("%d",&n);
	for(i=1;i<=8;i++){
		scanf("%d",&a[i]);
	}
	while(m<=n){
	sum1=0,sum2=0;
	for(i=1;i<=8;i++){
		scanf("%d",&b[i]);
		c[i]=a[i]^b[i];
		a[i]=c[i];
		sum1=sum1+(b[i]%2)+((b[i]/2)%2)+((b[i]/4)%2)+((b[i]/8)%2)+((b[i]/16)%2)+((b[i]/32)%2)+((b[i]/64)%2)+((b[i]/128)%2)+((b[i]/256)%2)+((b[i]/512)%2)+((b[i]/1024)%2)+((b[i]/2048)%2)+((b[i]/4096)%2)+((b[i]/8192)%2)+((b[i]/16384)%2)+((b[i]/32768)%2);
		sum2=sum2+(b[i]%16>9)+((b[i]/16)%16>9)+((b[i]/256)%16>9)+((b[i]/4096)%16>9);
		printf("%04X",c[i]);
	}
	printf(" ");
	printf("%d ",sum1);
	printf("%d\n",sum2);
	m++;
}
	return 0;
}