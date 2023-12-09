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
#define eps 1e-6
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
/*long long ans=1,sum=0;
char str[210];
int main()
{
	int l;
	char*p1,*p2,pos;
	scanf("%s",str);
	p1=str;l=strlen(str);
	while((p2=strchr(p1,'+'))!=NULL){
		ans=1;
		F(i,0,p2-p1){
			if(i%2==0){
				ans=ans*(str[i+p1-str]-'0');
			}
		}
		sum=sum+ans;
		p1=p2+1;
	}
	ans=1;
	F(i,p1-str,l-1){
		if(i%2==0)
		ans=ans*(str[i]-'0');
	}
	sum=sum+ans;
	printf("%lld",sum);
	return 0;
}*/
int main()
{
	int n,i=1;
	long long ans=1,sum=0;
	char ch;
	while(i){
		if(i%2==1)
		scanf("%d",&n);
		else
		scanf("%c",&ch);
		if(ch==EOF){
			ans=ans*n;
			sum=sum+ans;
		}break;
		if(ch=='*'){
			ans=ans*n;
		}
		else if(ch=='+'){
			ans=ans*n;
			sum=sum+ans;
			ans=1;
		}
		i++;
	}
	printf("%lld",sum);
	return 0;
}