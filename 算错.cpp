#include<stdio.h>
int main()
{
	int a,b,mul[100],MUL;
	int c,d,e,f,g,h,i,j;
	int m;
	m=1;
	scanf("%d%d",&a,&b);
	c=a/1000; d=(a%1000)/100; e=(a%100)/10; f=(a%10);
	g=b/1000; h=(b%1000)/100; i=(b%100)/10; j=(b%10);
	mul[1]=c*g;mul[2]=c*h;mul[3]=c*i;mul[4]=c*j;
	mul[5]=d*g;mul[6]=d*h;mul[7]=d*i;mul[8]=d*j;
	mul[9]=e*g;mul[10]=e*h;mul[11]=e*i;mul[12]=e*j;
	mul[13]=f*g;mul[14]=f*h;mul[15]=f*i;mul[16]=f*j;
	while(m<=16){
		if(mul[m]==40){
			mul[m]=35;
		}
		m++;
	}
	MUL=mul[1]*1000000+mul[2]*100000+mul[3]*10000+mul[4]*1000+mul[5]*100000+mul[6]*10000+mul[7]*1000+mul[8]*100+mul[9]*10000+mul[10]*1000+mul[11]*100+mul[12]*10+mul[13]*1000+mul[14]*100+mul[15]*10+mul[16];
	printf("%d",MUL);
	return 0;
}