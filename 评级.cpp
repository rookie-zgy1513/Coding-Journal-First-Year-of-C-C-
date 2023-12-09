#include<stdio.h>
int main()
{
	int score,a,b,c,d,e;
	a=b=c=d=e=0;
	while(scanf("%d",&score)!=EOF){
		if(score>=90){a++;
		printf("Lunatic\n");
		}
		else if(score>=80){
		b++;
		printf("Extra\n");
		}
		else if(score>=70){
		c++;
		printf("Hard\n");
		}
		else if(score>=60){
			d++;
		printf("Normal\n");
		}
		else{
		e++;
		printf("Easy\n");
		}
	}
	printf("%d %d %d %d %d",a,b,c,d,e);
	return 0;
}