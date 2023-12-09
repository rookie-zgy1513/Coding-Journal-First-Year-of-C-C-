#include<stdio.h>
int main()
{
	int n,m=1,a,b,op,c,d;
	double e,f;
	scanf("%d",&n);
	while(m<=n){
		scanf("%d%d%d%d%d",&a,&b,&op,&c,&d);
		if(op==1){
			e=a+c;
			f=b+d;
		}
		else if(op==2){
			e=a-c;
			f=b-d;
		}
		else if(op==3){
			e=a*c-b*d;
			f=b*c+a*d;
		}
		else if(op==4){
			e=(double)(a*c+b*d)/(c*c+d*d);
			f=(double)(b*c-a*d)/(c*c+d*d);
		}
		printf("%.2lf%+.2lfi\n",e,f);
		m++;
	}
	return 0;
}