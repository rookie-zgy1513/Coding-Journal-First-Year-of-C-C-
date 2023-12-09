#include<stdio.h>
int main()
{
	int c=0,miss=0;
	double a=0.0,b=0.0;
	int sum=0;
	char ch;
	ch=getchar();
	while(ch!=EOF){
		switch(ch){
		case 'M':
		c=0;
		miss++;	
		a=0.0;
		break;
	    case 'G':
		++c;	
		a=0.5;
		break;
		case 'P':
		++c;
		a=1.0;
		break;
	}
		switch(c/10+1){
			case 0:
				b=0.0;break;
			case 1:
			b=1.0;break;
			case 2:
			b=1.1;break;
			case 3:
			b=1.2;break;
			case 4:
			b=1.3;break;
			case 5:
			b=1.4;break;
			default:
			b=1.5;break;	
		}
		sum=sum+200*a*b;
		ch=getchar();
	}
	printf("%lld\n",sum);
	if(miss==0){
		printf("Full Combo!");
	}
	return 0;
}