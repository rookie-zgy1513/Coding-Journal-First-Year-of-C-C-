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
char str[300],s[300];
char op[300];
long long a[300],b[300];
long long sum;
int main()
{
	int l,i,j=0,k=0;
	gets(str);
	l=strlen(str);
	F(i,0,l-1){
		if(str[i]!=' '){
			s[j]=str[i];
			j++;
		}
	}
	l=j-1;
	j=0;
	F(i,0,l-1){
		if(isdigit(s[i])){
			a[j]=10*a[j]+s[i]-'0';
		}
		else{
			j++;
			op[k]=s[i];
			k++;
		}
	}
	F(i,0,j){
		switch(op[i]){
			case '*':
				a[i+1]=a[i]*a[i+1];
				a[i]=0;break;
			case '/':
				a[i+1]=a[i]/a[i+1];
				a[i]=0;break;
			case '+':
			break;
			case '-':
			a[i+1]=-a[i+1];
		}
	}
	F(i,0,j){
		sum=sum+a[i];
	}
	printf("%lld",sum);
	return 0;
}