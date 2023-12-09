#include<stdio.h>
int main()
{
	int n, a1,a2,a3,score,i,t;
	int sum=0;
	char ch;
	scanf("%d%d%d%d",&n,&a1,&a2,&a3);
	
	i=1;
	while(i<=n){
	    
		scanf(" %c",&ch);
		scanf("%d",&t);
		
		if(ch=='G'){
			score=t * a1;
		}
		else if(ch=='L'){
			score=t * a2;
		}
		else if(ch!='G'||ch!='L'){
			score=t * a3;
		}
		sum = sum + score;
		i++;
	}
	printf("%d", sum);
	return 0;
	
	
}