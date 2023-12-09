#include<stdio.h>
#include<math.h>
int main()
{
	int n[100];
	int m;
	long long int x;
	int c,w,b,d,i;
	i=0;
	w=1;
	while(i<=9){
		scanf("%d",&n[i]);
		i++;
	}
	scanf("%lld",&x);
	
	while((n[0]>=0)&&(n[1]>=0)&&(n[2]>=0)&&(n[3]>=0)&&(n[4]>=0)&&(n[5]>=0)&&(n[6]>=0)&&(n[7]>=0)&&(n[8]>=0)&&(n[9]>=0)){
	    b=log10(x);
		c=b;
		w=pow(10,c);
		m=x/w;
		if(c==0){
		n[m]=n[m]-1;	
		}
		else{
			n[m]=n[m]-1;
			while(c!=0){
				d=pow(10,c);	
				m=(x%d)/(d/10);
				n[m]=n[m]-1;
				c--;
			}
		}
		x++;
	}

	printf("%lld",x-2);
	return 0;
}
