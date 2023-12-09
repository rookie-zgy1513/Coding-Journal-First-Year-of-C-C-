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
char s[100];
int temp[100];
int main()
{
	long long l,flag=0;
	while(scanf("%s",s)!=EOF){
		flag=0;
		l=strlen(s);
		if(l==1&&s[0]=='0'){
			printf("0");printf("\n");
		}
		else{
		F(i,0,l-1){
			if(s[i]=='A')
		temp[i]=10;
		else if(s[i]=='B')
		temp[i]=11;
		else if(s[i]=='C')
		temp[i]=12;
		else if(s[i]=='D')
		temp[i]=13;
		else if(s[i]=='E')
		temp[i]=14;
		else if(s[i]=='F')
		temp[i]=15;
		else
		temp[i]=s[i]-'0';
		if(i!=0)
		printf("%d%d%d%d",((temp[i]>>3)&1),((temp[i]>>2)&1),((temp[i]>>1)&1),((temp[i]>>0)&1));
		else{
			for(int j=3;j>=0;j--){
				if(((temp[i]>>j)&1)==0&&flag==0)continue;
				else{
					printf("%d",(temp[i]>>j)&1);
					flag++;
				}	
			}
		}
		}
		printf("\n");
		}
		
	}
	return 0;
}