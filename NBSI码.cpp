#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int i=(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
char s[20];
int main()
{
	char c;
	long long sum;
	int cnt=0,i=-1,m=1,op;
	scanf("%s",s);
	while(cnt<3){
		i++;
		if(s[i]=='-'){cnt++;continue;
		}
		sum+=(s[i]-'0')*m;
		m++;
	}
	op=sum%11;
	if(op==10){
	c='X';	
	if(c==s[12])
	printf("Right");
	else{
		s[12]='X';
		printf("%s",s);
	}
	}
	else{
		if(op==(s[12]-'0'))
		printf("Right");
		else{
			s[12]=op-0+'0';
			printf("%s",s);
		}
		
	}
	return 0;
}