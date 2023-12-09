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
char op[100];
char s[100],tm[100],tn[100];
int main()
{
	int i=0,j=0,m,n,l,filelen,d=0;
	char*p;
	int flag=0;
	scanf("%s",op);
	getchar();
	gets(s);
	l=strlen(op);
	if(op[1]=='-'){
		flag=1;
		d=1;
	}
	p=strchr(op,':');
	F(i,1+d,p-op-1){
		tm[j++]=op[i];
	}
	m=atoi(tm);
	j=0;
	F(i,p-op+1,l-2){
		tn[j++]=op[i];
	}
	n=atoi(tn);
	l=strlen(s);
	filelen=MIN(m,l);
	if(flag){
		if(n-filelen<=0){
			F(i,0,filelen-1){
				putchar(s[i]);
			}
		}
		else{
			F(i,1,n-filelen)
			printf("#");
			F(i,0,filelen-1)
			printf("%c",s[i]);
		}
	}
	else{
		if(n-filelen<=0){
			F(i,0,filelen-1){
				putchar(s[i]);
			}
		}
		else{
			F(i,0,filelen-1)
			printf("%c",s[i]);
			F(i,1,n-filelen)
			printf("#");
		}
	}
	return 0;
	
}